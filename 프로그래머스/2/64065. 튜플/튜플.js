function solution(s) {
    const sets = tupleToArray(s);
    
    function tupleToArray(x) {
        const result = []
        
        x = x.slice(2, x.length - 2);
        for (const xx of x.split("},{")) {
        	result.push(xx.split(","));
        }
        
        return result;
    }
     
    const resultSet = new Set();
    
    sets.sort((a, b) => a.length - b.length);
    
    for (const subset of sets) {
        for (const num of subset) {
            resultSet.add(parseInt(num));
        }
    }
    
    return Array.from(resultSet);
}