function solution(routes) {
    routes = routes.sort((a, b) => a[1] - b[1]);
    
    let cnt = 0;
    let endOfRoutes = routes[0][1];
    
    for (const route of routes) {
        if (endOfRoutes < route[0]) {
            cnt++
            endOfRoutes = route[1];
        }
    }
    
    return cnt + 1;
}