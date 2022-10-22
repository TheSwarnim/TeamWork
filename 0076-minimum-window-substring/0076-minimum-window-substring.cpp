class Solution {
public:
    string minWindow(string s, string t) {
        int tcnt[150], cnt[150];
        memset(tcnt, 0, sizeof(tcnt));
        memset(cnt, 0, sizeof(cnt));
        
        for(int i = 0; i < t.size(); i++){
            tcnt[t[i]]++;
        }
        
        int x = INT_MAX, y = INT_MAX;
        for(int i = 0, j = 0; i < s.size(); i++){
            cnt[s[i]]++;
            while(j < i && (tcnt[s[j]] == 0 || tcnt[s[j]] < cnt[s[j]])){
                cnt[s[j++]]--;
            }
            bool flag = true;
            for(int i = 0; i < 150; i++){
                if(cnt[i] < tcnt[i]){
                    flag = false;
                    break;
                }
            }
            if(flag){
                if(x == INT_MAX || (y - x + 1) > (i - j + 1)){
                    x = j;
                    y = i;
                }
            }
        }
        
        return x == INT_MAX ? "" : s.substr(x, y - x + 1);
    }
};