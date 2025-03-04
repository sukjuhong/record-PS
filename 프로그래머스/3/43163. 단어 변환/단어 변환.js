function solution(begin, target, words) {
    let front = 0;
    const queue = []
    const map = new Map();
    
    queue.push([begin, 0]);
    map[begin] = true;
    
    while (front < queue.length) {
        const top = queue[front++];
        const curStr = top[0];
        const curCount = top[1];
        
        if (curStr === target) {
            return curCount; 
        }
        
        const filtered = words.filter((word) => diffStr(curStr, word) === 1)
        for (const word of filtered) {
            if (!map[word]) {
                queue.push([word, curCount + 1]);
                map[word] = true;
            }
        }
    }
    
    return 0;
}

function diffStr(x, y) {
    let cnt = 0;
    const n = x.length;
    for (let i=0; i<n; i++) {
        if (x[i] !== y[i]) {
            cnt++;
        }
    }
    return cnt;
}