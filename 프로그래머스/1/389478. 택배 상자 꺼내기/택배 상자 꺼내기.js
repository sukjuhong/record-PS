function solution(n, w, num) {
    const nh = Math.ceil(n / w);
    const numh = Math.ceil(num / w);
    
    const nw = n - w * (nh - 1);
    const numw = num - w * (numh - 1);
    
    let result = nh - numh;
    
    if (nh % 2 === numh % 2 && nw >= numw) {
        result++;
    } else if (nh % 2 !== numh % 2 && nw + numw >= w) {
        result++;
    }
    
    return result;
}