class Solution {
public:
    long long minCost(vector<int>& n, vector<int>& cost) {
        long long l = 1, r = 1e6, res = 0, res1 = 0;
        while(l < r){
            int m = (l+r)/2;
            res = res1 = 0;
            for(int i = 0; i < n.size(); i++){
                res += 1ll*cost[i]*abs(n[i] - m);
                res1 += 1ll*cost[i]*abs(n[i] - (m+1));
            }
            if(res < res1){
                r = m;
            } else {
                l = m+1;
            }
        }
        return min(res, res1);
    }
};