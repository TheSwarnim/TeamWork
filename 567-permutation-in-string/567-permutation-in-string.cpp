class Solution {
public:
    // just count the total characters in s1, s2 should have a same length
    // permutation == the cnt[] of s2 substring should be equal to cnt[] 
    // of s1
    
    bool checkInclusion(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        if(m < n) return false;
        
        int cnt[26]; // cnt character in s1
        memset(cnt, 0, sizeof(cnt));
        
        for(char &c : s1) cnt[c - 'a']++;
        
        for(int i = 0; i < m; i++) {
            cnt[s2[i] - 'a']--;
            
            if(i >= n) cnt[s2[i-n] - 'a']++;
            
            if(i >= n-1){
                bool flag = true;
                for(int i = 0; i < 26; i++)
                    if(cnt[i] != 0) {
                        flag = false;
                        break;
                    }
                if(flag) return true;
            }
        }
        
        return false;
    }
};