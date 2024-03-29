class Solution {
public:
    int mod = 1e9 + 7;
    int countVowelPermutation(int n) {
        long dp[n+1][5]; // n, (a, e, i, o, u)
        memset(dp, 0, sizeof(dp));
        for(int i = 1; i <= n; i++){
            if(i == 1) 
                for(int j = 0; j < 5; j++)
                    dp[i][j] = 1;
            else {
                dp[i][0] = (dp[i-1][1] + dp[i-1][2] + dp[i-1][4])%mod;
                dp[i][1] = (dp[i-1][0] + dp[i-1][2])%mod;
                dp[i][2] = (dp[i-1][1] + dp[i-1][3])%mod;
                dp[i][3] = (dp[i-1][2])%mod;
                dp[i][4] = (dp[i-1][2] + dp[i-1][3])%mod;
            }
        }
        long res = 0;
        for(int j = 0; j < 5; j++){
            res = (res + dp[n][j])%mod;
        }
        return res;
    }
};