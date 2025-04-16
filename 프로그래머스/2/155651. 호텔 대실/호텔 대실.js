function solution(book_time) {
    function timeToNum(time) {
        const [hour, minute] = time.split(":").map(Number)
        return hour * 60 + minute;
    }
    
    const bookTimes = book_time
    	.map(row => [timeToNum(row[0]), timeToNum(row[1]) + 10])
    	.sort((a, b) => a[0] - b[0]);
   
    let maxRooms = 0;
    const rooms = [];

    for (const [start, end] of bookTimes) {
        // 현재 예약 시작 전에 끝난 방 제거
        for (let i = 0; i < rooms.length; i++) {
            if (rooms[i] <= start) {
                rooms.splice(i, 1);
                i--; // 방 번호 밀림 방지
            }
        }
        rooms.push(end); // 새로운 방 사용
        maxRooms = Math.max(maxRooms, rooms.length);
    }
    
    return maxRooms;
}