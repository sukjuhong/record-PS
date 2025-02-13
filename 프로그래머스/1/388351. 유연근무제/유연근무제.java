import java.util.*;
import java.text.*;

class Solution {
    public int solution(int[] schedules, int[][] timelogs, int startday) {
        SimpleDateFormat sdf = new SimpleDateFormat("HHmm");
        int n = schedules.length;
        boolean[] flag = new boolean[n];
        int curDay = startday;
         
       	Date[] formattedSchedules = Arrays.stream(schedules)
            .mapToObj(s -> {
                try {
                    Date date = sdf.parse(String.format("%04d", s));
                    Calendar car = Calendar.getInstance();
                    car.setTime(date);
                    car.add(Calendar.MINUTE, 10);
                    return car.getTime();
                } catch (ParseException e) {
                    throw new RuntimeException(e);
                }
            })
            .toArray(Date[]::new);
        
        for (int i=0; i<7; i++) {
            if ((curDay - 1) % 7 < 5) {
                for (int j=0; j<n; j++) {
                   	try {
                        Date curTimeLog = sdf.parse(String.format("%04d", timelogs[j][i]));
                        if (curTimeLog.after(formattedSchedules[j])) {
                            flag[j] = true;
                        }
                    } catch (ParseException e) {
                        throw new RuntimeException(e);
                    }
                }
            }
            curDay++;
        }
        
        int count = 0;
        for (int i=0; i<n; i++) {
            if (!flag[i]) {
                count++;
            }
        }
        return count;
    }
}