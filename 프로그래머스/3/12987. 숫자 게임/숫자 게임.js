// 7 5 3 1
// 8 6 2 2
function solution(A, B) {
    let idxA = 0;
    let idxB = 0;
    
    const decrescent = (a, b) => b - a;
    
    A.sort(decrescent);
    B.sort(decrescent);
    
    let cnt = 0;
    
    while (idxA < A.length && idxB < B.length) {
        if (A[idxA] < B[idxB]) {
            cnt++;
            idxA++;
            idxB++;
        } else {
            idxA++;
            B.pop();
        }    
    }
    
    return cnt;
}