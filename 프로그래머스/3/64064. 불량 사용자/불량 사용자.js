function solution(user_id, banned_id) {
    const map = new Map();
    
    function isSameId(a, b) {
        if (a.length !== b.length) return false;
        for (let i=0; i<a.length; i++) {
            if (a[i] === "*") continue;
            if (a[i] !== b[i]) return false;
        }
        return true;
    }
    
    for (const b of banned_id) {
        map[b] = [];
        for (const u of user_id) {
            if (isSameId(b, u)) {
                map[b].push(u);
            }
        }
    }
    
    const resultSet = new Set();
    const set = new Set();
    
    function backTracking(idx) {
        if (idx === banned_id.length) {
            const result = [...set].sort().join("");
            resultSet.add(result);
            return;
        }
        
        for (const id of map[banned_id[idx]]) {
            if (!set.has(id)) {
                set.add(id);
                backTracking(idx+1);
                set.delete(id)
            }
        }
    }
    
    backTracking(0);
    
    return resultSet.size;
}