function solution(storage, requests) {
    const n = storage.length;
    const m = storage[0].length;
    
    const map = Array.from({ length: n+2 }, () => new Array(m+2).fill("."));
    
    for (let i=0; i<n; i++) {
        for (let j=0; j<m; j++) {
            map[i+1][j+1] = storage[i][j];
        }
    }
    
    for (const request of requests) {
        const alpha = request[0];
        if (request.length === 1) {
            bfs(map, n, m, 0, 0, alpha);
        } else if (request.length === 2) {
            for (let i=1; i<=n; i++) {
                for (let j=1; j<=m; j++) {
                    if (map[i][j] === alpha) {
                        map[i][j] = ".";
                    }
                }
            }
        }
    }
    
    let cnt = 0;
    for (let i=0; i<n; i++) {
        for (let j=0; j<m; j++) {
            if (map[i+1][j+1] !== ".") {
                cnt++;
            }
        }
    }
    return cnt;
}

function bfs(map, n, m, y, x, target) {
    const dy = [-1, 0, 0, 1];
    const dx = [0, 1, -1, 0];
    
    const visited = Array.from({ length: n+2 }, () => new Array(m+2).fill(false));
    const queue = [];
    let front = 0;
    queue.push([y, x]);
    
    while (front < queue.length) {
    	const [cy, cx] = queue[front++];
        
        for (let i=0; i<4; i++) {
            const [ny, nx] = [cy+dy[i], cx+dx[i]];
            if (ny < 0 || ny >= n+2 || nx < 0 || nx >= m+2) continue;
            if (visited[ny][nx]) continue;
            if (map[ny][nx] === target) {
                map[ny][nx] = ".";
            } else if (map[ny][nx] === ".") {
            	queue.push([ny, nx]);
            }
          	visited[ny][nx] = true;
        }
    }
}