class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& s) {
        int n = s.size();
        /*
        gas stations comes in increasing order
        dp[t] max distance I can cover if I fuel t-th times
        */
        long dp[501] = {startFuel};
        
        for(int i = 0; i < n; i++){
            for(int t = i; t >= 0 && dp[t] >= s[i][0]; t--){
                dp[t+1] = max(dp[t+1], s[i][1] + dp[t]);
            }
        }
        
        for(int t = 0; t <= n; t++){
            if(dp[t] >= target) return t;
        }
        return -1;
    }
};