function solution(priorities, location) {
    const arr = []
    const queue = []
    
    for (const [i, value] of priorities.entries()) {
        arr.push([i, value])
    }
    
    let front = 0;
    let exec = 0;
    while (front < arr.length) {
        const cur = arr[front++];
        
        const bigger = arr
        	.slice(front)
        	.find((pair) => pair[1] > cur[1])
        if (bigger) {
            arr.push(cur)
            continue;
        }
        
        exec++;
        if (cur[0] === location) {
            return exec;
        }
    }
    
    return -1;
}