function solution(triangle) {
    const n = triangle.length
    
    const memo = Array.from(new Array(n), () => new Array(n).fill(0))
    
    return dp(triangle, memo, n, 0, 0)
}

function dp(triangle, memo, size, i, j) {
   if (size <= i || size <= j) return 0
    
   if (memo[i][j] !== 0) return memo[i][j]
    
   return memo[i][j] = triangle[i][j] + Math.max(dp(triangle, memo, size, i+1, j), dp(triangle, memo, size, i+1, j+1));
}