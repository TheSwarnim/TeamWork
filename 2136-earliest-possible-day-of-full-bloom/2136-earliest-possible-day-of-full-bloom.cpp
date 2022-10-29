class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int n = plantTime.size();
        
        vector<pair<int, int>> time(n);
        for(int i = 0; i < n; i++){
            time[i] = {plantTime[i], growTime[i]};
        }
        
        sort(begin(time), end(time), 
             [&](pair<int, int> &a, pair<int, int> &b){
            return  a.second == b.second ? 
                    a.first < b.first : 
                    a.second > b.second;
        });
        
        int mxTime = 0, ttlPlantTime = 0;
        for(auto [pTime, gTime] : time){
            ttlPlantTime += pTime;
            mxTime = max(mxTime, ttlPlantTime + gTime);
        }
        
        return mxTime;
    }
};