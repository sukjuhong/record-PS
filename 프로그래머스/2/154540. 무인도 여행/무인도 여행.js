const dY = [-1, 0, 0, 1]
const dX = [0, -1, 1, 0]

function solution(maps) {
    const n = maps.length;
    const m = maps[0].length;
    
    const visited = Array.from(Array(n), () => Array(m).fill(0))
    const cnts = []
    
    for (let i=0; i<n; i++) {
        for (let j=0; j<m; j++) {
            if (maps[i][j] !== "X" && visited[i][j] === 0) {
                const cnt = bfs(maps, visited, n, m, i, j)
                cnts.push(cnt)
            }
        }
    }
    
    cnts.sort((a, b) => a - b)
    
    return cnts.length === 0 ? [-1] : cnts
}

function bfs(maps, visited, n, m, i, j) {
    let cnt = 0;
    
    const queue = [[i, j]];
    visited[i][j] = 1;
    
    let front = 0;
    
    while (front < queue.length) {
        const [curY, curX] = queue[front++];
        
        cnt += parseInt(maps[curY][curX], 10)
        
        for (let i=0; i<4; i++) {
            const nxtY = curY + dY[i];
            const nxtX = curX + dX[i];
            if (nxtX < 0 || nxtX >= m || nxtY < 0 || nxtY >= n) continue;
            if (maps[nxtY][nxtX] === "X") continue;
            if (visited[nxtY][nxtX] !== 1) {
                queue.push([nxtY, nxtX])
                visited[nxtY][nxtX] = 1;
            }
        }
    }
    
    return cnt;
}