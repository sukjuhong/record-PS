import java.util.*;

class Solution {
    public String solution(String[] participant, String[] completion) {
        Map<String, Integer> participantMap =
            new HashMap<>();
        
        for (String person: participant) {
            if (participantMap.get(person) == null) {
                participantMap.put(person, 1);
            } else participantMap.merge(person, 1, Integer::sum);
        }
        
        for (String person: completion) {
            participantMap.merge(person, 1, (a, b) -> a - b);
            if (participantMap.get(person) == 0) {
                participantMap.remove(person);
            }
        }
        
        StringBuilder sb = new StringBuilder();
        for (String key: participantMap.keySet()) {
            sb.append(key);
        }
        return sb.toString();
    }
}