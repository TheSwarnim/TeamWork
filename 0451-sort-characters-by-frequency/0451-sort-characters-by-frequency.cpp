class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        vector<string> bucket(s.size()+1, "");
        string res;
        
        for(auto &c : s){
            freq[c]++;
        }
        
        for(auto &it : freq){
            bucket[it.second].append(it.second, it.first);
        }
        
        for(int i = s.size(); i >= 1; i--){
            if(!bucket[i].empty()){
                res.append(bucket[i]);
            }
        }
        
        return res;
    }
};