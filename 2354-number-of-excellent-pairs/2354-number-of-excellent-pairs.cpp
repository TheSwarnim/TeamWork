class Solution {
public:
    typedef long long ll;
    
    long long countExcellentPairs(vector<int>& A, int k) {
        ll cnt[30] = {}, res = 0;
        for(int a : unordered_set<int>(begin(A), end(A)))
            cnt[__builtin_popcount(a)]++;
        for(int i = 1; i < 30; i++){
            for(int j = 1; j < 30; j++){
                if(i+j >= k)
                    res += cnt[i]*cnt[j];
            }
        }
        return res;
    }
};