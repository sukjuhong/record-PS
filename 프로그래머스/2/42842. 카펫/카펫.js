function solution(brown, yellow) {
    // x는 가로, y는 세로
    // brown = 2x + 2y - 4
    // yellow = (x-2) * (y-2) = xy -2x - 2y + 4
    // 전체 카펫의 크기 = xy = brown + yellow
    
    // 예제에서 xy = 12
    // x를 늘리면서 진행?
    const xy = brown + yellow;
    for (let x=1; x<xy; x++) {
        if (xy % x !== 0) continue;
        const y = Math.floor(xy / x);
        if (2*x + 2*y - 4 === brown && (x-2) * (y-2) === yellow) return [x, y].sort((a, b) => b - a)
    }
    return [-1, -1]
}