function solution(n, times) { 
    function binarySearch(left, right) {
        if (left > right) return left;
        
        const mid = Math.floor((left + right) / 2);
        const flag = check(mid);
        
        if (flag >= 0) {
            return binarySearch(left, mid - 1);
        }
        return binarySearch(mid + 1, right);
    }
    
    function check(time) {
        let cnt = 0;
        for (const t of times) {
            cnt += Math.floor(time / t);
        }
        return cnt - n;
    }
    
 	return binarySearch(1, Math.max(...times) * n);
}