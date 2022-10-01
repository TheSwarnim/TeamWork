class Solution {
    public int numDecodings(String s) {
        int n = s.length();
        dp = new int[n+1];
        Arrays.fill(dp, -1);
        dp[n] = 1;
        // return findNumDecodings(s, 0);
        
        for(int i = n-1; i >= 0; i--){
            char c = s.charAt(i);
            
            if(c == '0'){
                dp[i] = 0;
            } else {
                dp[i] = dp[i+1];
                
                if(i < n-1 && (c == '1' || c == '2' && s.charAt(i+1) < '7')){
                    dp[i] += dp[i+2];
                }
            }
        }
        
        return dp[0];
    }
    
    int[] dp;
    private int findNumDecodings(String s, int idx){
        int n = s.length();
        if(idx == n){
            return 1;
        }
        
        if(dp[idx] != -1){
            return dp[idx];
        }
        
        char c = s.charAt(idx);
        if(c == '0'){
            return 0;
        }
        
        int res = findNumDecodings(s, idx+1);
        if(idx < n-1 && (c == '1' || c == '2' && s.charAt(idx+1) < '7')){
            res += findNumDecodings(s, idx+2);
        }
        
        return dp[idx] = res;
    }
}