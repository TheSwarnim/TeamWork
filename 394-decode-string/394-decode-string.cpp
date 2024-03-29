class Solution {
public:
    string decodeString(string &s, int &i){
        string res;
        
        while(i < s.length() && s[i] != ']'){
            if(!isdigit(s[i])){
                res += s[i++];
            }
            else {
                int n = 0;
                while(i < s.length() && isdigit(s[i])){
                    n = n * 10 + s[i++] - '0';
                }
                
                i++;
                // cout << i << endl;
                string t = decodeString(s, i);
                i++;
                // cout << i << endl;
                
                while(n-- > 0){
                    res += t;
                }
            }
        }
        
        return res;
    }
    
    string decodeString(string s) {
        int i = 0;
        return decodeString(s, i);
    }
};