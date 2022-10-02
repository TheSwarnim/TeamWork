class Solution {
    int mod = (int)(1e9) + 7;
    
    int[][] dp = new int[31][1001];
    
    public int numRollsToTarget(int n, int k, int target) {
        for(int i = 0; i < dp.length; i++){
            Arrays.fill(dp[i], -1);
        }
        
        return numRollsToTargetUtil(n, k, target);
    }
    
    private int numRollsToTargetUtil(int n, int k, int target){
        if(n == 0){
            if(target == 0){
                return 1;
            }
            return 0;
        }
        
        if(dp[n][target] != -1){
            return dp[n][target];
        }
        
        long ttl = 0;
        for(int i = 1; i <= Math.min(k, target - (n-1)); i++){
            ttl = (ttl + numRollsToTargetUtil(n-1, k, target - i)) % mod;
        }
        
        return dp[n][target] = (int)(ttl);
    }
}