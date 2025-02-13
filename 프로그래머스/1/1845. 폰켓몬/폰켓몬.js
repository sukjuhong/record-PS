function solution(nums) {
    const visited = new Set();
    let count = 0;
    
    for (const num of nums) {
        if (!visited.has(num)) {
            visited.add(num);
            count++;
        }
    }
    
    return Math.min(count, nums.length/2);
}