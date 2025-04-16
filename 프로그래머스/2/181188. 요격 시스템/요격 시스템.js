function solution(targets) {
    const sortedTargets = targets
    	.sort((a, b) => a[1] - b[1]);
    
    let cnt = 0;
    let line = -1;
    sortedTargets.forEach(([start, end]) => {
		if (line < start) {
            cnt++;
     		line = end - 0.5;       
        }
    })
    return cnt;
}