class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& s) {
        if(startFuel >= target) return 0;
        int n = s.size(), maxdist = startFuel, stops = 0, i = 0;
        priority_queue<int> pq;
        while(maxdist < target){
            while(i < n && maxdist >= s[i][0]){
                pq.push(s[i++][1]);
            }
            if(pq.empty()) return -1;
            maxdist += pq.top(); pq.pop();
            stops++;
        }
        return stops;
    }
};