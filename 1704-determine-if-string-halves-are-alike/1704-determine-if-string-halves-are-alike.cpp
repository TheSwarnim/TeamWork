class Solution {
public:
    bool halvesAreAlike(string s) {
        int cnt1 = 0, cnt2 = 0;
        for(int i = 0; i < s.length(); i++){
            if(i < s.length()/2){
                cnt1 += isVowel(s[i]);
            } else {
                cnt2 += isVowel(s[i]);
            }
        }
        return cnt1 == cnt2;
    }
    
    bool isVowel(char &c){
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' 
            || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
};