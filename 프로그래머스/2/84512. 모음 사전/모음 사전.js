function solution(word) {
    const arr = []
    
    const gathers = ["A", "E", "I", "O", "U"];
    
    let check = false;
    let cnt = 0;
    let result = 0;
    
    function dfs() { 
        if (check) return;
        
        if (arr.length !== 0) cnt++;
        
        if (arr.join("") === word) {
            result = cnt;
            check = true;
            return;
        }
        
      	if (arr.length === 5) return;
         
        for (const gather of gathers) {
            arr.push(gather)
            dfs();
            arr.pop();
        }
    }
    
    dfs();
    
    return result;
}