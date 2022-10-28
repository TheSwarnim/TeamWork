class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        int n = strs.size();
        unordered_map<string, vector<string>> mp;
        for(string &str : strs){
            mp[getKey(str)].push_back(str);
        }
        for(auto p : mp){
            res.push_back(p.second);
        }
        return res;
    }
    
    string getKey(string s){
        sort(s.begin(), s.end());
        return s;
    }
};