/**
	1. 왼쪽 빈칸 찾기
    2. 오른쪽 퍼즐 찾기
    3. 퍼즐 수 대로 정렬하고 투포인터 순회
    4. 길이가 같다면 4방향으로 돌리면서 비교
*/
function solution(game_board, table) {
    const n = game_board.length; 
    
    const dY = [-1, 0, 0, 1];
    const dX = [0, 1, -1, 0];
     
	function dfs(map, visited, n, startY, startX, target) {
        const stack = [[startY, startX]];
        visited[startY][startX] = true;

        const result = [];
        let minY = startY, minX = startX;

        while (stack.length !== 0) {
            const [curY, curX] = stack.pop();

            result.push([curY, curX]);

            for (let i=0; i<4; i++) {
                const [nxtY, nxtX] = [curY + dY[i], curX + dX[i]];
                if (nxtY < 0 || nxtY >= n || nxtX < 0 || nxtX >= n) continue;
                if (visited[nxtY][nxtX]) continue;
                if (map[nxtY][nxtX] !== target) continue;
                stack.push([nxtY, nxtX]);
                visited[nxtY][nxtX] = true;
                minY = Math.min(minY, nxtY);
                minX = Math.min(minX, nxtX);
            }
        }

        return result
            .map(([y, x]) => [y-minY, x-minX])
        	.sort((a, b) => a[0] - b[0] || a[1] - b[1]);
    }
    
    function rotate(shape) {
        const maxRow = Math.max(...shape.map(([r]) => r));
        const maxCol = Math.max(...shape.map(([_, c]) => c));
        return shape
            .map(([r, c]) => [c, maxRow - r])
        	.sort((a, b) => a[0] - b[0] || a[1] - b[1]);;
    }
    
    function isSameShape(shape1, shape2) {
    	return shape1.length === shape2.length &&
        	shape1.every(([r, c], i) => r === shape2[i][0] && c === shape2[i][1]);
    }
    
   function extractPieces(n, board, targetValue) {
       const pieces = [];
       const visited = Array.from({ length: n }, () => new Array(n).fill(false));

       for (let i = 0; i < n; i++) {
			for (let j = 0; j < n; j++) {
				if (board[i][j] === targetValue && !visited[i][j]) {
    				const piece = dfs(board, visited, n, i, j, targetValue);
    				pieces.push(piece);
				}
			}
		}
       
		return pieces;
	}
    
	const blanks = extractPieces(n, game_board, 0);
    const puzzles = extractPieces(n, table, 1);
     
    blanks.sort((a, b) => a.length - b.length);
    puzzles.sort((a, b) => a.length - b.length); 
    
    let filled = 0;
    const used = new Array(puzzles.length).fill(false);

    for (const space of blanks) {
        for (let i = 0; i < puzzles.length; i++) {
            if (used[i]) continue;

            let piece = puzzles[i];
            for (let r = 0; r < 4; r++) {
                if (isSameShape(space, piece)) {
                    filled += space.length;
                    used[i] = true;
                    break;
                }
                piece = rotate(piece);
            }
            if (used[i]) break;
        }
    }

    return filled;
}
