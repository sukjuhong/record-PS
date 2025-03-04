function solution(record) {
    const map = new Map();
    
    const buffer = [];
    
    for (const command of record) {
        const [cmd, uid, uname] = command.split(" ");
        
        if (cmd !== "Leave") {      
        	map[uid] = uname;
        }    
        
        if (cmd !== "Change") {
            buffer.push([cmd, uid]);
        }
    }    
    
    return buffer.map((cmd) => 
        `${map[cmd[1]]}님이 ${cmd[0] === "Enter" ? "들어왔습니다." : "나갔습니다."}`
    );
}