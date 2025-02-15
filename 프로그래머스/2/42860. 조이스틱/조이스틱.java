class Solution {
    public int solution(String name) {
        int n = name.length();
        
        // 최악의 경우의 수 (한쪽으로 쭉 가는 것)
        int minMoves = n - 1;
        int diffs = 0;
        
        for (int cursor=0; cursor<n; cursor++) {
            // 각 지점에서 알파벳을 변환하는 횟수는 일정함
            diffs += this.calcCharDiff(name.charAt(cursor));
            
            // 다음 연결된 A의 끝을 찾음
            int nxtCursor = cursor + 1;
            while (nxtCursor < n && name.charAt(nxtCursor) == 'A') {
                nxtCursor++;
            }
            
            // 연결된 A의 끝이 한개 이상일 때
            if (nxtCursor - cursor > 1) {
                // 현재 커서에서 왼쪽으로 A가 끝나는 지점까지 간다면
                // 온 커서만큼 다시 움직이고 cursor * 2
                // A가 끝나는 지점까지 움직여야함
                int movesToLeft = cursor * 2 + n - nxtCursor;
                
                // A가 끝나는 지점에서 오른쪽으로 현재 커서까지 온다면
                // A가 끝나는 지점에서 끝까지 움직이고 (n - nxtCursor) * 2
                // 현재 커서까지 와야함
                int movesToRight = (n-nxtCursor) * 2 + cursor;
                minMoves = Math.min(minMoves, movesToLeft);
                minMoves = Math.min(minMoves, movesToRight);
            }
        }    
        
        return diffs + minMoves;
    }    
    
    public int calcCharDiff(char c) {
        return Math.min(
            c - 'A',
            'Z' - c + 1
        );
    }
}