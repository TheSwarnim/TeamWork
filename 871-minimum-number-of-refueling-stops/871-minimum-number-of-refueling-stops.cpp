class Solution {
public:
    int minRefuelStops(int target, int cur, vector<vector<int>>& s) {
        int n = s.size(),res = 0, i = 0;
        priority_queue<int> pq;
        while(cur < target){
            while(i < n && s[i][0] <= cur)
                pq.push(s[i++][1]);
            if(pq.empty()) return -1;
            cur += pq.top(); pq.pop();
            res++;
        }
        return res;
    }
};