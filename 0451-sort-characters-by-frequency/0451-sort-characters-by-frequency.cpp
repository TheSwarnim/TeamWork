class Solution {
public:
    string frequencySort(string s) {
        vector<pair<int, char>> cnt(150);
        for(char c : s){
            cnt[c].first++;
            cnt[c].second = c;
        }
        sort(cnt.rbegin(), cnt.rend());
        string res;
        for(auto p : cnt){
            res += string(p.first, p.second);
        }
        return res;
    }
};