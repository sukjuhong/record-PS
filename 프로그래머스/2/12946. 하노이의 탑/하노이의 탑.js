function solution(n) {
    const answer = [];
    
    hanoi(answer, n, 1, 2, 3);
    
    return answer;
}

function hanoi(arr, n, a, b, c) {
    if (n === 0) return;
    hanoi(arr, n-1, a, c, b);
    arr.push([a, c])
    hanoi(arr, n-1, b, a, c);
}