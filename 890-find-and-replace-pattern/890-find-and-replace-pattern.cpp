class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        string p = F(pattern);
        cout << p << endl;
        vector<string> res;
        for(auto w : words) {
            if(F(w) == p) res.push_back(w);
        }
        return res;
    }
    
    string F(string w){
        unordered_map<char, int> m;
        for(char &c : w) if(!m.count(c)) m[c] = m.size();
        for(int i = 0; i < w.size(); i++) w[i] = 'a' + m[w[i]];
        return w;
    }
};