class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        int s = stamp.size(), t = target.size();
        if(s > t) return {};
        vector<int> res;
        int total_stamp = 0, turn_stamp = -1;
        while(turn_stamp){
            turn_stamp = 0;
            for(int sz = stamp.size(); sz > 0; sz--){
                for(int i = 0; i <= s - sz; i++){
                    string new_stamp = string(i, '*') 
                        + stamp.substr(i, sz) + string(s - sz - i, '*');
                    auto pos = target.find(new_stamp);
                    while(pos != string::npos){
                        res.push_back(pos);
                        turn_stamp += sz;
                        fill(begin(target)+pos, begin(target) + pos + s, '*');
                        pos = target.find(new_stamp);
                    }
                }
            }
            total_stamp += turn_stamp;
        }
        reverse(begin(res), end(res));
        return total_stamp == t ? res : vector<int>();
    }
};