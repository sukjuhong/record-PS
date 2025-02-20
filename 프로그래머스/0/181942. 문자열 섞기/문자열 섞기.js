function solution(str1, str2) {
    const n = str1.length;
    let answer = '';
    
    for (let i=0; i<n; i++) {
        answer += str1[i];
        answer += str2[i];
    }
    
    return answer;
}