class Solution {
    public int numDecodings(String s) {
        dp = new int[s.length()];
        Arrays.fill(dp, -1);
        return findNumDecodings(s, 0);
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