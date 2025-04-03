function solution(points, routes) {
    const x = routes.length; // 로봇 수
    const robots = routes.map(route => points[route[0] - 1].slice()); // 로봇의 현재 위치
    const paths = routes.map(route => route.map(idx => points[idx - 1])); // 각 로봇의 전체 경로
    const progress = new Array(x).fill(0); // 현재 목표 인덱스
    const finished = new Array(x).fill(false); // 도착한 로봇 여부
    let cnt = 0; // 충돌 횟수
    let activeRobots = x; // 이동 중인 로봇 수

    function moveRobots() {
        for (let i = 0; i < x; i++) {
            if (finished[i]) continue; // 도착한 로봇은 움직이지 않음

            const robot = robots[i];
            const dest = paths[i][progress[i] + 1];

            if (robot[0] !== dest[0]) {
                robot[0] += Math.sign(dest[0] - robot[0]);
            } else if (robot[1] !== dest[1]) {
                robot[1] += Math.sign(dest[1] - robot[1]);
            }

        }
    }

    function countCollisions() {
        const map = new Map();
        
        for (let i = 0; i < x; i++) {
            if (finished[i]) continue; // 도착한 로봇은 충돌 검사에서 제외

            const key = `${robots[i][0]}-${robots[i][1]}`;
            map.set(key, (map.get(key) || 0) + 1);
        }

        cnt += [...map.values()].filter(v => v > 1).length;
    }
    
    function checkFinished() {
        for (let i=0; i<x; i++) {
            if (finished[i]) continue;
            
            const robot = robots[i];
            const dest = paths[i][progress[i] + 1];
            
            if (robot[0] === dest[0] && robot[1] === dest[1]) {
                progress[i]++;
                if (progress[i] === paths[i].length - 1) {
                    finished[i] = true;
                    activeRobots--;
                }
            }
        }
    }

    countCollisions();
    while (activeRobots > 0) {
        moveRobots();
        countCollisions();
        checkFinished();
    }

    return cnt;
}
