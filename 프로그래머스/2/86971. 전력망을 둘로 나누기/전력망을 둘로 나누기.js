function solution(n, wires) {
    let answer = 100;
    
    const graph = [[]]
   	for (const [l, r] of wires) {
        graph[l] ? graph[l].push(r) : graph[l] = [r]
        graph[r] ? graph[r].push(l) : graph[r] = [l]
    }
    
    for (const edge of wires) {
        const lCnt = getNodeCount(n, graph, edge[0], edge)
        const rCnt = n - lCnt
        
        const diff = Math.abs(lCnt - rCnt)
        answer = Math.min(answer, diff)
    }
    
    return answer;
}

function getNodeCount(n, graph, startNode, excludeEdge) {
    const visited = new Array(n+1)
    for (let i=1; i<=n; i++) {
        visited.push(0)
    }
    
    let cnt = 1
    const q = []
    q.push(startNode)
    visited[startNode] = 1
    while (q.length !== 0) {
        const curNode = q[0]
        q.shift()
        
        for (const connectNode of graph[curNode] || []) {
            if (Math.min(curNode, connectNode) === Math.min(...excludeEdge)
               && Math.max(curNode, connectNode) === Math.max(...excludeEdge)) continue; 
            
            if (visited[connectNode]) continue;
            
            q.push(connectNode)
            visited[connectNode] = 1
            cnt++
        }
    }
    
    return cnt
}
