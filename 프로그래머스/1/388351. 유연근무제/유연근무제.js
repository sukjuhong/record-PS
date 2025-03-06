function solution(schedules, timelogs, startday) {
    const n = schedules.length;
    const flags = new Array(n).fill(true);
    
    for (let i = 0; i < n; i++) {
        let day = startday; // 요일을 개별적으로 관리
        
        for (let j = 0; j < 7; j++) { 
            // 주말이면 넘어감 (j를 증가시키지 않고 요일만 갱신)
            if (day === 6 || day === 7) {
                day = (day % 7) + 1;
                continue;
            }
            
            const timelog = timelogs[i][j];

            // 출근 기록이 없거나, 지각한 경우만 false 처리
            if (timelog === undefined || timeToMin(timelog) > timeToMin(schedules[i]) + 10) {
                flags[i] = false;
            }
            
            // 다음 요일로 이동
            day = (day % 7) + 1;
        }
    }
    
    return flags.filter(flag => flag).length;
}

function timeToMin(x) {
    return Math.floor(x / 100) * 60 + x % 100;
}
