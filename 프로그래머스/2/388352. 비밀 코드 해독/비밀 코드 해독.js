function solution(n, q, ans) {
    let cnt = 0;
    const arr = [];
    
    function permutation(n, c, start) {
        if (arr.length === c) {
            const result = q.map((query) => getCntCorrect(query, arr))
            if (isArrSame(result, ans)) {
                cnt++;
            }
            return
        }
        
        for (let i=start; i<=n; i++) {
            arr.push(i);
            permutation(n, c, i+1);
            arr.pop();
        }
    }
    
    permutation(n, 5, 1);
    
    return cnt;
}

function getCntCorrect(arrA, arrB) {
    return arrA.filter((val) => arrB.indexOf(val) !== -1).length;
}

function isArrSame(arrA, arrB) {
    let flag = true;
    for (let i=0; i<arrA.length; i++) {
        if (arrA[i] !== arrB[i]) {
            flag = false;
            break;
        }
    }
    return flag;
}