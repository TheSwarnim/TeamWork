class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        int dp[k+1][n+1];
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i <= k; i++){
            for(int j = 0; j <= n; j++){
                if(i == 0 || j == 0){
                    dp[i][j] = 0;
                } else {
                    int res = dp[i][j-1];
                    for(int k = 1; k < j; k++){
                        // cout << dp[i-1][k] << " " << prices[j-1] << " " << prices[k-1] << endl;
                        res = max(res, dp[i-1][k] + prices[j-1] - prices[k-1]);
                    }
                    dp[i][j] = res;
                }
            }
        }
        return dp[k][n];
    }
};