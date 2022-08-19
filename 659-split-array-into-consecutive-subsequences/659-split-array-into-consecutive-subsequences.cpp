class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, priority_queue<int, vector<int>, greater<int>>> mp;
        for(int &x : nums){
            auto &pq = mp[x-1];
            if(pq.empty()){
                mp[x].push(1);
            } else {
                int val = pq.top();
                pq.pop();
                mp[x].push(val+1);
            }
        }
        
        for(auto &vals : mp){
            auto &pq = vals.second;
            while(!pq.empty()){
                if(pq.top() < 3) return false;
                pq.pop();
            }
        }
        
        return true;
    }
};