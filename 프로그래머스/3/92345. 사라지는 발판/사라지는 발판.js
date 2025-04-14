function solution(board, aloc, bloc) {
    const moves = [
        [0, -1],
        [1, 0],
        [-1, 0],
        [0, 1]
    ];
    function dfs(board, aloc, bloc) {
        if (board[aloc[0]][aloc[1]] === 0) return { win: false, cnt: 0 };
        
        const nexts = [];
        for (const move of moves) {
            const nc = aloc[0]+move[0];
            const nr = aloc[1]+move[1];
            if (nc < 0 || nc >= board.length ||
               nr < 0 || nr >= board[0].length ||
               board[nc][nr] === 0) continue;
            nexts.push([nc, nr]);
        }
        
        if (nexts.length === 0) return { win: false, cnt: 0 };
        
        const results = [];
        board[aloc[0]][aloc[1]] = 0;
        for (const next of nexts) {
            results.push(dfs(board, bloc, next));
        }
        board[aloc[0]][aloc[1]] = 1;
        
        let flag = false;
        let minCnt = Infinity;
        let maxCnt = 0;
        for (let result of results) {
            flag = flag || !result.win;
            if (!result.win) minCnt = Math.min(minCnt, result.cnt)
            else maxCnt = Math.max(maxCnt, result.cnt);
        }

        if (flag) {
            return { win: true, cnt: minCnt+1 };

        } else {
            return { win: false, cnt: maxCnt+1 };
        }
    }
    
    return dfs(board, aloc, bloc).cnt;
}