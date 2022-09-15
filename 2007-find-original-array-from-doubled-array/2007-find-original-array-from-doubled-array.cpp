class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();
        if(n%2) return {};
        
        map<int, int> cnt;
        for(int &x : changed){
            cnt[x]++;
        }
        vector<int> res;
        for(auto [x, f] : cnt){
            // cout << x << " " << f << endl;
            if(f == 0) continue;
            if(cnt.find(2*x) == cnt.end() or cnt[2*x] < f){
                return {};
            } else {
                cnt[2*x] -= f;
                if(x == 0){
                    if(f%2 != 0) return {};
                    else f /= 2;
                }
                while(f--){
                    res.push_back(x);
                }
            }
        }
        // for(auto [x, f] : cnt){
        //     cout << x << " " << f << endl;
        //     if(cnt[2*x] < cnt[x]){
        //         return {};
        //     } else{
        //         cnt[2*x] -= cnt[x];
        //         while(f--){
        //             res.push_back(x);
        //         }
        //     }
        // }
        return res;
    }
};