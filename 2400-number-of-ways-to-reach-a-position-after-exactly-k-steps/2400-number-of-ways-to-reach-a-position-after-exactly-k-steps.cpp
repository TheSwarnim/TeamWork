class Solution {
public:
    int dp[1000][1001] = {};
    int mod = 1e9 + 7;
    int dfs(int d, int k){
        if(d >= k){
            return d == k;
        }
        if(dp[d][k] == 0)
            dp[d][k] = (1 + dfs(d+1, k-1) + dfs(d + (d != 0 ? -1 : 1), k - 1)) % mod;
        return dp[d][k] - 1;
    }
    
    int numberOfWays(int startPos, int endPos, int k) {
        return dfs(abs(startPos - endPos), k);
    }
};