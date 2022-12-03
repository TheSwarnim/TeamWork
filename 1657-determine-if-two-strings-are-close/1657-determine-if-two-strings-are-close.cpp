class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int> cnt1(26), cnt2(26);
        unordered_set<char> s1, s2;
        for(auto c : word1){
            cnt1[c - 'a']++;
            s1.insert(c);
        }
        for(auto c : word2){
            cnt2[c - 'a']++;
            s2.insert(c);
        }
        sort(begin(cnt1), end(cnt1));
        sort(begin(cnt2), end(cnt2));
        return cnt1 == cnt2 && s1 == s2;
    }
};