class Solution {
public:
    int mod = 1e9 + 7;
    typedef long long ll;
    
    ll dp[int(1e5+1)] = {};
    int numberOfArrays(string s, int k) {
        return dfs(s, 0, k);
    }
    
    int dfs(string &s, int i, int k){
        if(i == s.length())
            return 1;
        if(s[i] == '0')
            return 0;
        if(dp[i] == 0){
            for(ll sz = 1, val = 0; i+sz <= s.length(); sz++) {
                val = val*10 + s[i+sz-1] - '0';
                if(val > k) break;
                dp[i] = (dp[i] + dfs(s, i+sz, k)) % mod;
            }
        }
        return dp[i];
    }
};