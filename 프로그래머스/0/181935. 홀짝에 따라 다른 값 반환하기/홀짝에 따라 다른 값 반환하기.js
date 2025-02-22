function solution(n) {
    let sum = 0;
    if (n & 1 === 1) {
        while (n > 0) {
            sum += n;
            n -= 2;
        }
    } else {
        while (n > 0) {
            sum += Math.pow(n, 2);
            n -= 2;
        }
    }
    return sum;
}