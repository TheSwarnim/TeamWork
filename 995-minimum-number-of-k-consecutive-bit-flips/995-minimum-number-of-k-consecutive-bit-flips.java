class Solution {
    public int minKBitFlips(int[] nums, int k) {
        int n = nums.length;
        int dp[] = new int[n+1];
        int count = 0, res = 0;
        
        for(int i = 0; i < n; i++){
            count += dp[i];
            int flip = count%2 == 0 ? 0 : 1;
            if( (flip^nums[i]) == 1 ){
                continue;
            }
            
            if(i+k > n){
                // System.out.println(i + " " + count);
                return -1;
            }
            
            res++;
            count++;
            dp[i+k] -= 1;
        }
        
        return res;
    }
}