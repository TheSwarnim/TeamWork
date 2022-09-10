class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        
        if(k >= n/2){
            int res = 0;
            for(int i = 1; i < n; i++){
                res += max(0, prices[i] - prices[i-1]);
            }
            return res;
        }
        
        int dp[k+1][n];
        memset(dp, 0, sizeof(dp));
        for(int i = 1; i <= k; i++){
            int localMax = dp[i-1][0] - prices[0];
            for(int j = 1; j < n; j++){
                dp[i][j] = max(dp[i][j-1], prices[j] + localMax);
                localMax = max(localMax, dp[i-1][j] - prices[j]);
            }
        }
        return dp[k][n-1];
    }
};