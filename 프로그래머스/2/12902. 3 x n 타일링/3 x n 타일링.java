class Solution {
    public static final int MOD = 1_000_000_007;
    
    public int solution(int n) {
        long[] arr = new long[n+1];
        
        arr[0] = 1;
        arr[2] = 3;
        
        for (int i=4; i<=n; i+=2) {
        	arr[i] += arr[i-2] * 3;
            for (int j=i-4; j>=0; j-=2) {
                arr[i] += arr[j] * 2;
            }
            arr[i] %= MOD;
        }
        
        return (int) arr[n];
    }
}