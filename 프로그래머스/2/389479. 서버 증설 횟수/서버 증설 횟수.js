function solution(players, m, k) {
    const queue = [];
    let front = 0;
    
    let time = 0;
    let serverCount = 1;
    let totalAddedServerCount = 0;
    
    for (const player of players) {
        // 서버 반납
        while (front < queue.length) {
            const top = queue[front];
            
            if (top[1] === time) {
                front++;
  				serverCount -= top[0];
            } else break;
        }    
        
        let curServerCount = serverCount;
        
        // 서버 증설
        while (player >= curServerCount * m) {
            curServerCount++;
            totalAddedServerCount++;
        }
         
        if (serverCount !== curServerCount) {
            const diff = curServerCount - serverCount;
            queue.push([curServerCount - serverCount, time + k]);
            serverCount += diff;
        }
         
        time++;
    }
    
    return totalAddedServerCount;
}