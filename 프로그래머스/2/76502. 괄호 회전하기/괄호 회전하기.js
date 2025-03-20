function solution(s) {
    let cnt = 0;
    
    if (s.length % 2 !== 0) {
        return 0;
    }
    
    function rotate(x) {
        const first = x[0];
        return x.slice(1) + first;
    }
    
    function isValid(x) {
        const stack = [];
        for (const c of x) {
            switch (c) {
                case ")":
                    if (stack.pop() !== "(") return false;
                    break;
                case "]":
                    if (stack.pop() !== "[") return false;
                    break;
                case "}":
                    if (stack.pop() !== "{") return false;
                    break;
                default:
                    stack.push(c);
            }
        } 
        return true;
    }
    
    for (let i=0; i<s.length; i++) {
        s = rotate(s);
        if (isValid(s)) {
            cnt++;
        }
    }
    
    return cnt;
}