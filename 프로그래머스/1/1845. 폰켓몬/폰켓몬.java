class Solution {
    public int solution(int[] nums) {
        int n = nums.length;
        boolean[] visited = new boolean[200001];
      	int count = 0;
        
        for (int i=0; i<n; i++) {
            int cur = nums[i];
            if (!visited[cur]) {
                count++;
                visited[cur] = true;
            }
        }
        
        return Math.min(n / 2, count);
    }
    
}