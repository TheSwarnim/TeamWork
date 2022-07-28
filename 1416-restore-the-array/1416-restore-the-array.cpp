class Solution {
public:
    int mod = 1e9 + 7;
    typedef long long ll;
    ll dp[100001] = {};
    int numberOfArrays(string s, int k) {
        int n = s.length();
        fill(dp, dp+n, 0);
        for(int i = n; i >= 0; i--){
            if(i == n) dp[n] = 1;
            else if(s[i] == '0') dp[i] = 0;
            else {
                for(ll j = 1, val = 0; j+i <= n; j++){
                    val = val*10 + s[i+j-1] - '0';
                    if(val > k) break;
                    dp[i] = (dp[i] + dp[i+j]) % mod;
                }
            }
        }
        return dp[0];
    }
};