function solution(n) {
    function bfs(n, open, close) {
        if (open === n) {
            return 1;
        } else if (open - close < 0) {
            return 0;
        }
        let result = 0;
        result += bfs(n, open + 1, close);
        result += bfs(n, open, close + 1);
        return result;
    }
    
    return bfs(n, 0, 0);
}