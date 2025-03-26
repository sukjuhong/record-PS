function solution(arr) {
    const n = arr.length;
    const result = [0, 0];
    
    function isFilled(arr, startX, startY, size) {
        const first = arr[startX][startY];
        
        for (let i=startX; i<startX + size; i++) {
            for (let j=startY; j<startY + size; j++) {
                if (arr[i][j] !== first) return -1;
            }
        }
        
        return first;
    }
    
    function compression(arr, startX, startY, size) {
        let value = isFilled(arr, startX, startY, size);
        
        if (value !== -1) {
            result[value]++;
            return;
        }
    	
        const halfSize = Math.floor(size / 2);
        compression(arr, startX, startY, halfSize);
        compression(arr, startX + halfSize, startY, halfSize);
        compression(arr, startX, startY + halfSize, halfSize);
        compression(arr, startX + halfSize, startY + halfSize, halfSize);
    }
    
    compression(arr, 0, 0, n);
    
    return result;
}