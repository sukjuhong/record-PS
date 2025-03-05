// 백트래킹 문제
function solution(info, edges) {
    const n = info.length;
    const graph = Array.from({ length: n }, () => []);
    
    for (const edge of edges) {
        graph[edge[0]].push(edge[1]);
    }
    
     let maxSheepCount = 0;
    
    function dfs(sheepCount, wolfCount, now, nxts) {
        info[now] ? wolfCount++ : sheepCount++;
        if (sheepCount <= wolfCount) return;
        maxSheepCount = Math.max(maxSheepCount, sheepCount);
        
        for (const nxt of nxts) {
            for (const node of graph[nxt]) {
                if (nxts.indexOf(node) === -1) {
                    nxts.push(node);
                    dfs(sheepCount, wolfCount, node, nxts);
                    nxts.pop();
                }
            }
        }
        
        return maxSheepCount;
    }
    
    return dfs(0, 0, 0, [0]);
}