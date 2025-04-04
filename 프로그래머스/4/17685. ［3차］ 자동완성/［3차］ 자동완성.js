/**
또 다른 방법이 하나 더 있는데요. 
전체 단어를 사전 순으로 정렬한다면, 어떤 단어와 앞부분이 가장 많이 일치하는 단어는 정렬 후 인접한 두 단어 중 하나가 됩니다.
이 방법을 이용하면 모든 단어 쌍이 아닌, 정렬 후에 인접한 단어 쌍만 비교하면 되므로 빠르게 문제를 해결할 수 있습니다.
*/
function solution(words) {
    words = words.sort();
    
    function compare(x, y) {
        let cnt = 0;
        const n = Math.min(x.length, y.length);
        for (let i=0; i<n; i++) {
            if (x[i] === y[i]) {
                cnt++;
            } else break;
        }
        return cnt;
    }
    
    let totalCnt = 0;
    
    const n = words.length;
    for (let i=0; i<n; i++) {
        let cnt = 0;
        const cursor = words[i];
        
        if (i !== 0) {
            cnt = Math.max(cnt, compare(cursor, words[i-1]));
        }
        
        if (i !== n-1) {
            cnt = Math.max(cnt, compare(cursor, words[i+1]));
        }
        
        if (cnt !== cursor.length) {
            cnt++;
        }
        
        totalCnt += cnt;
    }
    
    return totalCnt;
}