class Solution {
public:
    /*
    range 10^9
    pos = 10
    tight = 0 or 1
    mask = bit from 0 to 1111111111(10 ones) = 2^10 - 1 = 1024
    
    dp[pos][tight][sum]
    dp[10][2][1024]
    
    the function contains
    g(string str, int pos = 0, int tight = 1, int sum = 0)
    */
    
    int dp[10][2][1024];
    int g(string &str, int pos = 0, int tight = 1, int mask = 0){
        if(pos == str.size()){
            return mask != 0;
        }
        else if(dp[pos][tight][mask] != -1){
            return dp[pos][tight][mask];
        }
        else if(tight == 1){
            int res = 0;
            for(int i = 0; i <= str[pos] - '0'; i++){
                // check if digit repeated, ie, present in the mask
                if(mask & (1 << i)) continue;
                
                int newMask = (mask == 0 && i == 0 ? mask : mask | (1<<i));
                if(str[pos] - '0' == i){
                    res += g(str, pos+1, 1, newMask);
                } else {
                    res += g(str, pos+1, 0, newMask);
                }
            }
            return dp[pos][tight][mask] = res;
        }
        else {
            int res = 0;
            for(int i = 0; i < 10; i++){
                if(mask & (1<<i)) continue;
                
                int newMask = (mask == 0 && i == 0 ? mask : mask | (1<<i));
                res += g(str, pos+1, 0, newMask);
            }
            return dp[pos][tight][mask] = res;
        }
    }
    
    int countSpecialNumbers(int n) {
        string s = to_string(n);
        memset(dp, -1, sizeof(dp));
        return g(s);
    }
};