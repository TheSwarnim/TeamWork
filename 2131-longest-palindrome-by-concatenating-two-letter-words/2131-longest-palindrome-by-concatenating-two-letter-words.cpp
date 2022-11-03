class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> same, diff;
        int res = 0, mxsame = 0;
        string mxstr;
        for(auto &w : words){
            if(w[0] == w[1]){
                same[w]++;
            } else {
                diff[w]++;
            }
        }
        for(auto &p : same){
            if(p.second%2 == 1 && mxsame < p.second){
                mxsame = p.second;
                mxstr = p.first;
            }
        }
        res += mxsame*2;
        for(auto &w : words){
            if(w[0] == w[1]) {
                if(w != mxstr){
                    res += 4*(same[w]/2);
                    same[w] = 0;
                }
                
                continue;
            }
            
            string opp = w;
            reverse(opp.begin(), opp.end());
            // cout << w << " " << opp << endl;
            int val = min(diff[w], diff[opp]);
            diff[w] -= val;
            diff[opp] -= val;
            res += 4*val;
        }
        
        return res;
    }
};