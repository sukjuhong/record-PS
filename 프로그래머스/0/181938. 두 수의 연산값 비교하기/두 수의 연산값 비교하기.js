function solution(a, b) {
    const l = parseInt(`${a}${b}`)
    const r = 2*a*b
    return Math.max(l, r);
}