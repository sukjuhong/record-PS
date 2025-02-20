function solution(a, b) {
    const l = parseInt(`${a}${b}`)
    const r = parseInt(`${b}${a}`)
    return Math.max(l, r)
}