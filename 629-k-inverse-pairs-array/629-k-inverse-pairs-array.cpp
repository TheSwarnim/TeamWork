class Solution {
public:
    /*
    1) thinking of dp for the first time
    */
    int mod = 1e9+7;
    typedef long long ll;
    int kInversePairs(int n, int k) {
        if(k > n*(n-1)/2 || k < 0) return 0;
        // after this line of execution below,
        // it will make sure that n >= 2
        if(k == 0 || k == n*(n-1)/2) return 1;
        
        ll dp[n+1][k+1];
        memset(dp, 0, sizeof(dp));
        dp[2][0] = dp[2][1] = 1;
        
        for(int i = 3; i <= n; i++){
            dp[i][0] = 1;
            for(int j = 1; j <= min(k, i*(i-1)/2); j++){
                dp[i][j] = dp[i][j-1] + dp[i-1][j];
                if(j >= i) dp[i][j] -= dp[i-1][j-i];
                dp[i][j] = (dp[i][j]+mod)%mod;
            }
        }
        
        return (int)dp[n][k];
    }
};