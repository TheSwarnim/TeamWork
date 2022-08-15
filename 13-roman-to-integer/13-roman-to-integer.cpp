class Solution {
public:
    unordered_map<char, int> mp = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };
    
    int romanToInt(string s) {
        queue<int> q;
        for(char &c : s){
            q.push(mp[c]);
        }
        int ans = 0;
        while(!q.empty()){
            int val = q.front();
            q.pop();
            int nextval = -1;
            if(!q.empty()){
                if(q.front() > val){
                    nextval = q.front();
                    q.pop();
                }
            }
            if(nextval == -1){
                ans += val;
            } else {
                ans += (nextval - val);
            }
        }
        return ans;
    }
};