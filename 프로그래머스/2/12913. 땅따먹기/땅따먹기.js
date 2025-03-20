function solution(land) {
    const col = land.length;
    const row = land[0].length;
    
    const dp = land.slice();
    
    for (let i=1; i<col; i++) {
        for (let j=0; j<row; j++) {
            const prevLand = dp[i-1].slice();
            prevLand[j] = 0;
            dp[i][j] += Math.max(...prevLand);
        }
    }
    
    return Math.max(...dp[col - 1]);
}