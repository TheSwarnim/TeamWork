class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        for(int i = 0; i < s.length(); i++){
            if(!st.empty() && (isupper(s[i]) && st.top() == (char)(tolower(s[i])) || (islower(s[i]) && st.top() == (char)(toupper(s[i]))) ) ){
                st.pop();
            } else {
                st.push(s[i]);
            }
        }
        s = "";
        while(!st.empty()){
            s += st.top();
            st.pop();
        }
        reverse(s.begin(), s.end());
        return s;
    }
};