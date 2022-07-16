class Solution {
public:
    
    /*
    1. the idea is to traverse dfs while decresing the maxmoves each 
    time we proceed further, if reaches at edges of grid then we 
    increment the count (wrong approach)
    
    2. related topic : dp
    thinking of a 3d dp[MaxMove+1][m][n]
    the approach is that every next move will store the sum of 
    previous move
    
    -> understand after seeing vlad solution fully that the answer is
    the total sum of moves from the start idx we can move
    */

    int mod = 1e9+7;
    int findPaths(int m, int n, int maxMove, int ridx, int cidx) {
        long long dp[51][50][50];
        memset(dp, 0, sizeof(dp));
        for(int move = 1; move <= maxMove; move++){
            for(int i = 0; i < m; i++){
                for(int j = 0; j < n; j++){
                    dp[move][i][j] = (
                        (i == 0 ? 1 : dp[move-1][i-1][j]) +
                        (i == m-1 ? 1 : dp[move-1][i+1][j]) +
                        (j == 0 ? 1 : dp[move-1][i][j-1]) + 
                        (j == n-1 ? 1 : dp[move-1][i][j+1])
                    ) % mod;
                }
            }
        }
        return dp[maxMove][ridx][cidx];
    }
};