class Solution {
public:
    int mod = 1e9 + 7;
    int maxPerformance(int n, vector<int>& s, vector<int>& e, int k) {
        vector<vector<int>> ess(n);
        for(int i = 0; i < n; i++){
            ess[i] = {e[i], s[i]};
        }
        sort(rbegin(ess), rend(ess));
        priority_queue<int, vector<int>, greater<int>> pq; // we use it as min heap
        long long speed = 0, res =0;
        for(auto es : ess){
            speed += es[1];
            pq.push(es[1]);
            if(pq.size() > k){
                speed -= pq.top();
                pq.pop();
            }
            res = max(res, speed*es[0]);
        }
        return res%mod;
    }
};