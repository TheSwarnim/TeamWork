class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int, int>> ess(n);
        for(int i = 0; i < n; i++){
            ess[i] = {efficiency[i], speed[i]};
        }
        
        sort(rbegin(ess), rend(ess)); // sort by max eff then by max speed
        
        priority_queue<int, vector<int>, greater<int>> q; // min heap
        
        long sum = 0, res =0;
        for(auto &[e, s] : ess){
            sum += s;
            q.push(s);
            if(q.size() > k){
                sum -= q.top();
                q.pop();
            }
            res = max(res, sum*e);
        }
        return res%(int)(1e9 + 7);
    }
};