class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        priority_queue<int> pq; // pq is defined such that we always
        // choose that event first whose ending date is coming soon
        unordered_map<int, vector<int>> mp;
        for(auto e : events){
            mp[e[0]].push_back(e[1]);
        }
        
        int res = 0;
        for(int i = 1; i <= 1e5; i++){
            while(!pq.empty() && abs(pq.top()) < i){
                pq.pop();
            }
            for(auto val : mp[i]){
                pq.push(-val);
            }
            if(pq.size() > 0){
                pq.pop();
                res++;
            }
        }
        
        return res;
    }
};