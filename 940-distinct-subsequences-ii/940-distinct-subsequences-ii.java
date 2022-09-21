class Solution {
    public int distinctSubseqII(String s) {
        int n = s.length(), mod = (int)(1e9) + 7;
        long[] dp = new long[n+1];
        dp[0] = 1;
        Map<Character,Integer> lo = new HashMap<>();
        for(int i = 1; i < dp.length; i++){
            dp[i] = (2*dp[i-1])%mod;
            
            char ch = s.charAt(i-1);
            if(lo.containsKey(ch)){
                int j = lo.get(ch);
                dp[i] = (dp[i] - dp[j-1] + mod)%mod;
            }
            lo.put(ch, i);
        }
        return (int)(dp[n] - 1 + mod)%mod;
    }
}