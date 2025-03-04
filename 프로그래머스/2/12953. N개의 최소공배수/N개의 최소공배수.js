function solution(arr) {
    return arr
        .reduce((acc, val) => lcm(acc, val), arr[0]);
}

function lcm(x, y) {
    return x * y / gcd(x, y)
}

function gcd(x, y) {
    while (y !== 0) {
        [x, y] = [y, x % y];
    }
    return x;
}