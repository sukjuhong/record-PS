// 왜 값이 균등해야 각 원소의 곱이 최대가 될까?
// n개로 이루어진 집합 x1, x2, ..., xn이라고 하자
// 임의의 두 수 a, b (a < b) 에서 거리를 좁혀보자.
// (a-1) * (b+1) = ab + (b-a) -1
// b-a >= 1 이므로 ab보다 크다.
function solution(n, s) {
    if (s < n) return [-1];
    
    // S를 n으로 나눈 몫의 수로 n개를 채우고
    // 그중 S를 n으로 나눈 나머지의 수를 1만큼 더해주면 됨.
    const result = [];
    const share = Math.floor(s / n);
   	const remain = s % n;
    
    for (let i=0; i<n-remain; i++) {
        result.push(share);
    }
    
    for (let i=0; i<remain; i++) {
        result.push(share+1);
    }
    
    return result;
}