import java.util.*;

public class Solution {
    public int[] solution(int []arr) {
        List<Integer> answer = new ArrayList<>();
        
        int last = -1;
        for (int num : arr) {
            if (last != num) {
        		answer.add(num);
                last = num;
            }
        }

        return answer.stream()
            .mapToInt(Integer::intValue)
            .toArray();
    }
}