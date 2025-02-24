function isPrime(num) {
    if (num <= 1) return false;
    for (let i=2; i*i<=num; i++) {
        if (num % i === 0) return false;
    } 
    return true;
}

function permutation(numbers, arr, set, visited, depth) { 
    const n = numbers.length
    
    if (depth === n) return 0;
    
    let result = 0;
    
    for (let i=0; i<n; i++) {
        if (visited[i]) continue;
        arr.push(numbers[i]);
        visited[i] = true;
        const cur = parseInt(arr.join(""));
        if (!set[cur] && isPrime(cur)) result++;
        set[cur] = 1;
        result += permutation(numbers, arr, set, visited, depth+1);
        arr.pop();
        visited[i] = false;
    }
    
    return result;
}

function solution(numbers) { 
    const n = numbers.length;
    
    const arr = []
    const set = new Set();
    const visited = new Array(n).fill(false)
    
    const cnt = permutation(numbers, arr, set, visited, 0)
    
    return cnt;
}