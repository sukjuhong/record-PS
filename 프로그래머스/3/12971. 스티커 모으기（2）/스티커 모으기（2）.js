// dp[i] = Math.max(sticker[i] + dp[i-2], dp[i-1]);
function solution(sticker) {
    if (sticker.length === 1) return sticker[0];
    
    function dp(sticker) {
        const n = sticker.length;
        
        if (n === 0) return 0;
        if (n === 1) return sticker[0];
        
        const cache = new Array(n).fill(0);
        
        cache[0] = sticker[0];
        cache[1] = Math.max(sticker[0], sticker[1])
        
        for (let i=2; i<n; i++) {
            cache[i] = Math.max(sticker[i] + cache[i-2], cache[i-1]);
        }
        
        return cache[n - 1];
    }
    
    return Math.max(
        dp(sticker.slice(0, sticker.length - 1)),
        dp(sticker.slice(1))
    );
}