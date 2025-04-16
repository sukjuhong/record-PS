function solution(book_time) {
    function timeToNum(time) {
        const [hour, minute] = time
        	.split(":")
        return parseInt(hour) * 60 + parseInt(minute);
    }
    
    const bookTimes = book_time
    	.map(row => [timeToNum(row[0]), timeToNum(row[1])])
    	.map(row => [row[0], row[1] + 10])
    	.sort((a, b) => a[1] - b[1]);
   
    let maxCnt = 1;
    for (let i=0; i<bookTimes.length; i++) {
        let cnt = 1;
        for (let j=i+1; j<bookTimes.length; j++) {
            if (bookTimes[i][0] < bookTimes[j][1] &&
               bookTimes[i][1] > bookTimes[j][0]) {
                cnt++;
            }
        }
        maxCnt = Math.max(maxCnt, cnt);
    }
    
    return maxCnt;
}