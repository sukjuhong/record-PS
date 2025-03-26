function solution(n, left, right) {
    const arr = [];
    
	for (let i=left; i<=right; i++) {
        const div = Math.floor(i / n);
        const mod = i % n;
        arr.push(Math.max(div, mod) + 1);
    }    
    
    return arr;
}