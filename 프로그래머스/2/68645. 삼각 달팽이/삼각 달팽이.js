function solution(n) {
    const result = new Array(n)
    for (let i=0; i<n; i++) {
        result[i] = new Array(i+1);
    }
    
    let size = n;
    let y = 0;
    let x = 0;
    let num = 1;
    while (true) {
        const nxtNum = fill(result, y, x, num, size)
        num = nxtNum;
        y += 2; x++;
        size -= 3;
        if (size <= 0) break;
    }
    
    return result.flat();
}

function fill(result, y, x, num, size) { 
    for (let i=0; i<size; i++) {
        if (i !== 0) y++;
        result[y][x] = num++;
    }
    
    for (let i=1; i<size; i++) {
        if (i !== 0) x++;
        result[y][x] = num++;
    }
    
    for (let i=1; i<size-1; i++) {
        if (i !== 0) {
            y--; x--;
        }
        result[y][x] = num++;
    }
    
    return num;
}