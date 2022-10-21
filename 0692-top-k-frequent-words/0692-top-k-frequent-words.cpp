class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        for(auto &w : words){
            mp[w]++;
        }
        vector<pair<int, string>> li;
        for(auto &p : mp){
            li.push_back({-p.second, p.first});
        }
        sort(li.begin(), li.end());
        vector<string> res;
        for(int i = 0; i < li.size() && res.size() < k; i++){
            res.push_back(li[i].second);
        }
        return res;
    }
};