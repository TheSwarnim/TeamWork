class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int, int> win, looses;
        for(auto &m : matches){
            win[m[0]]++;
            looses[m[1]]++;
        }
        vector<int> warr, larr;
        for(auto &w : win){
            if(looses.find(w.first) == looses.end()){
                warr.push_back(w.first);
            }
        }
        for(auto &l : looses){
            if(l.second == 1){
                larr.push_back(l.first);
            }
        }
        return {warr, larr};
    }
};