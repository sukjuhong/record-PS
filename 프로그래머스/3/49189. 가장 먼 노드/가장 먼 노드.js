function solution(n, edge) {
    const matrix = Array.from({ length: n + 1 }, () => []);
    
    for (const [dept, dest] of edge) {
        matrix[dept].push(dest);
        matrix[dest].push(dept);
    }
    
    const visited = new Array(n + 1).fill(false);
    const queue = [];
    let front = 0;
    queue.push([1, 0]);
    visited[1] = true;
    
    let maxDist = 0;
    let maxCnt = 0;
    
    while (front < queue.length) {
        const [curNode, curDist] = queue[front++];
        
        for (const nxtNode of matrix[curNode]) {
            if (visited[nxtNode]) continue;
            queue.push([nxtNode, curDist+1]);
            visited[nxtNode] = true;
            if (maxDist < curDist + 1) {
                maxDist = curDist + 1;
                maxCnt = 1;
            } else {
                maxCnt++;
            }
        }
    }
    
    return maxCnt;
}