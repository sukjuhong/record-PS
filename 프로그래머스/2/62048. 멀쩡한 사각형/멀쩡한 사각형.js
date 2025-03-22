function solution(w, h) {
    function lcm(a, b) {
        if (b === 0) {
            return a
        }
        return lcm(b, a%b);
    }
    
    const s = lcm(w, h);
    const sw = Math.floor(w / s);
    const sh = Math.floor(h / s);
    return w * h - (sw + sh - 1) * s;
}