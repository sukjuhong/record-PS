function solution(n, money) {
    const MOD = 1_000_000_007;
    const dp = new Array(n+1).fill(0);
    
    dp[0] = 1;
    
    for (const coin of money) {
        for (let i=coin; i<n+1; i++) {
            dp[i] += dp[i-coin];
            dp[i] %= MOD;
        }
    }
    
    return dp[n];
}