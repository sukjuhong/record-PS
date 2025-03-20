function solution(msg) {
    const map = new Map();
    
    for (let i=0; i<26; i++) {
        map[String.fromCharCode("A".charCodeAt(0) + i)] = i+1;
    }
    
    
    const result = [];
    let i = 0;
    let mapLen = 26;
    while (i < msg.length) {
        let chunk = msg[i];
        
        while (i + 1 < msg.length) {
            if (map[chunk + msg[i + 1]]) {
                chunk += msg[i + 1];
                i++;
            } else break;
        }
        
        result.push(map[chunk]);
        
        if (i + 1 < msg.length) {
            map[chunk + msg[i + 1]] = ++mapLen;
        }
		i++;
    }
    
    return result;
}