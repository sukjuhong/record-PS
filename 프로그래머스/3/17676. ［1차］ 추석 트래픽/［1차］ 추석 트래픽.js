function solution(lines) {
    let maxCnt = 1;
    
    /**
    	두 로그의 차이를 계산합니다.
    */
    function calculateLogDiff(xLog, yLog) {
    	const xLogEndTime = getTime(xLog, true);  
        const yLogStartTime = getTime(yLog, false);
        return yLogStartTime - xLogEndTime;
    }
    
    /**
    	로그의 시간을 구합니다.
        밀리세컨드 단위
    */
    function getTime(log, isEnd) {
        let result = 0;
        
        const [_, time, duration] = log.split(" ");
        
        const [hour, minute, second] = time.split(":");
        
        result += hour * 3_600_000
        result += minute * 60_000;
        result += second * 1000;
        
        if (!isEnd) {
            let processingTime = parseFloat(duration.slice(0, -1));
            result -= processingTime * 1000 - 1;
        }
        
        return result;
    }
    
    const n = lines.length;
    
    for (let i=0; i<n; i++) {
        let cnt = 1;
        const leftLog = lines[i];
        
        for (let j=i+1; j<n; j++) {
            const rightLog = lines[j];
            const logDiff = calculateLogDiff(leftLog, rightLog);
            
            if (logDiff < 1000) {
                cnt++;
            }
        }
        
        maxCnt = Math.max(maxCnt, cnt);
    }
    
    return maxCnt;
}