class Solution {
public:
    vector<string> map = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_set<string> uset;
        for(string &s : words){
            uset.insert(findTransformation(s));
        }
        return uset.size();
    }
    
    string findTransformation(string &s){
        string ans;
        for(char &c : s){
            ans += map[c - 'a'];
        }
        return ans;
    }
};