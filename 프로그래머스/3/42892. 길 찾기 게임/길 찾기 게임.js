function solution(nodeinfo) {
    const nodeMap = []
    
    let maxX = 0;
    
    for (const [i, node] of nodeinfo.entries()) {
        nodeMap.push({
            visited: false,
            idx: i+1,
            y: node[1],
            x: node[0] 
        });
        maxX = Math.max(maxX, node[0]);
    }
    
    nodeMap.sort((a, b) => {
        if (a.y === b.y) {
            return a.x - b.x;
        }
        return b.y - a.y;
    })
     
    const rootNode = {
        idx: nodeMap[0].idx,
        y: nodeMap[0].y,
        x: nodeMap[0].x,
        left: null,
       	right: null,
    }
    nodeMap[0].visited = true;
    
    fillTree(nodeMap, rootNode, 0, maxX, 0); 
    
    return [
        preOrder(rootNode),
        postOrder(rootNode)
    ];
}

function fillTree(nodeMap, node, left, right, idx) { 
    for (let i=idx+1; i<nodeMap.length; i++) { 
        if (!node.left &&
            (nodeMap[i].x >= left && nodeMap[i].x < node.x) &&
            !nodeMap[i].visited) {
            node.left = nodeMap[i]
            nodeMap[i].visited = true;
            fillTree(nodeMap, node.left, left, node.x, i);
        }
        
        if (!node.right &&
            (nodeMap[i].x <= right && nodeMap[i].x > node.x) &&
            !nodeMap[i].visited) {
            node.right = nodeMap[i];
            nodeMap[i].visited = true;
            fillTree(nodeMap, node.right, node.x, right, i);
        }
        
        if (node.left && node.right) {
            break;
        }
    }
}

function preOrder(node) {
    const result = []
 
    result.push(node.idx)
    if (node.left) result.push(...preOrder(node.left))
    if (node.right) result.push(...preOrder(node.right))
    
    return result;
}

function postOrder(node) {
    const result = []
    
    if (node.left) result.push(...postOrder(node.left))
    if (node.right) result.push(...postOrder(node.right))
    result.push(node.idx)
    
    return result;
}