function solution(n)
{
    let cnt = 0;
    while (n > 0) {
        if (n % 2 === 0) {
            n = Math.floor(n / 2);
        } else {
            n -= 1;
            cnt++;
        }
    }
    return cnt;
}