// 숫자가 늘어나는게 math.floor(m / digit)
function solution(n, t, m, p) {
    let result = "";
    let curNum = 0;
    let curOrder = 0; 
 
    while (true) {
        const curNumStr = curNum.toString(n).toUpperCase();
        
        for (const digit of curNumStr) {
            if (curOrder + 1 === p) {
                result += digit;
            }
            
            curOrder = (curOrder+1) % m;
        }
        
        if (result.length >= t) {
            break;
        }
        
        curNum++;
    }
    
    return result.slice(0, t);
}
