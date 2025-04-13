function solution(n, t, m, timetable) {
    
    function changeTimeToNum(timeStr) {
        let [hour, minute] = timeStr.split(":");
       	hour = parseInt(hour);
        minute = parseInt(minute);
        return hour * 60 + minute;
    }
    
    function changeNumToTime(num) {
        const hour = Math.floor(num / 60);
        const minute = num - hour * 60;
        return String(hour).padStart(2, "0") + ":" +
            String(minute).padStart(2, "0")
    }
    
    timetable = timetable
        .map(row => changeTimeToNum(row))
        .sort((a, b) => b - a);
   
    let result;
    let shuttleTime = changeTimeToNum("09:00");
    
    for (let i=0; i<n; i++) {
        if (i !== 0) {
            shuttleTime += t;
        }
        
        let limit = m;
        
        result = shuttleTime;
        
        while (timetable.length !== 0 &&
               timetable[timetable.length - 1] <= shuttleTime) {
            limit--;
            let tmp = timetable.pop();
            if (limit === 0) {
                result = tmp - 1;
                break;
            }
        }
    }
    
    return changeNumToTime(result);
}
