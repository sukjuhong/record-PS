function solution(participant, completion) {
    const participantMap = new Map();
    
    for (const person of participant) {
        let count = participantMap.get(person) || 0;
        participantMap.set(person, count + 1);
    }
    
    for (const person of completion) {
        let count = participantMap.get(person);
        if (count == 1) participantMap.delete(person);
        else participantMap.set(person, count - 1);
    }
    
    let answer;
    for (const [key, value] of participantMap) {
        answer = key;
    }
    return answer;
}