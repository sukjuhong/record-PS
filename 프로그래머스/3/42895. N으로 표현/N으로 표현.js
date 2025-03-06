const operations = ["+", "-", "*", "/"];

function solution(N, number) {
   	const dp = Array.from({ length: 10 }, () => []);
    
    for (let i=1; i<=9; i++) {
        const set = new Set();
        set.add(parseInt(N.toString().repeat(i)));
        
        for (let j=1; j<i; j++) {
            for (const left of dp[i-j]) {
                for (const right of dp[j]) {
                    for (const op of operations) {
                        if (op === "/" && right === 0) continue;
                        set.add(Math.floor(eval(`(${left}) ${op} (${right})`)));
                    }
                }
            }
        }
        
        dp[i].push(...set.keys());
        
        if (set.has(number)) {
            return i;
        }
    }
    
    return -1;
}