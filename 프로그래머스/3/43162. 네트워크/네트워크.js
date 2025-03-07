function solution(n, computers) {
    const visited = new Array(n).fill(false);
    const queue = []
    let front = 0;
    
    let cnt = 0;
    
    while (visited.filter(flag => !flag).length !== 0) {
        for (let i=0; i<n; i++) {
            if (!visited[i]) {
            	bfs(i);
                cnt++;
            }
        }
    }
    
    function bfs(start) {
        queue.push(start);
        visited[start] = true;
        
        while (front < queue.length) {
            const curNode = queue[front++];

            for (let i=0; i<n; i++) {
                if (curNode === i || !computers[curNode][i]) continue;
                if (visited[i]) continue;
                queue.push(i);
                visited[i] = true;
            }
        }
    }
    
    return cnt;
}