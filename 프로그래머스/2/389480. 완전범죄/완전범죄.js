function solution(info, n, m) {
    const len = info.length;
    const cache = new Set();
    
    let min = Number.MAX_SAFE_INTEGER;
    
    function dfs(idx, a, b) {
        if (idx >= len) {
            min = Math.min(min, a)
            return;
        }
        
        const key = `${idx}-${a}-${b}`;
        if (cache.has(key)) {
            return;
        }
        cache.add(key);
        
        const newA = a + info[idx][0];
        const newB = b + info[idx][1];
        
        if (newA < n) {
            dfs(idx+1, newA, b);
        }
        
        if (newB < m) {
            dfs(idx+1, a, newB);
        }
    }
    
    dfs(0, 0, 0);
    
    return min === Number.MAX_SAFE_INTEGER ? -1 : min;
}