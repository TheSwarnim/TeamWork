class Solution {
public:

    /**
     * the question is asking to remove duplicates from the string whose frequency is 
     * k, so the idea is that we use a stack to store the characters and the frequency 
     * of each character.
     * Every time when we loop through the string, we check if the current character
     * is the top most element in the stack. If it is, we pop the top most element
     * and check if the frequency is k. If it is, we do nothing otherwise we push the
     * current character and its new frequency into the stack.
    */
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> st; 
        for(char c : s){
            if(st.empty() || st.top().first != c) // if the stack is empty or the top element is not the current character we push the current character and its frequency into the stack
                st.push({c, 1});
            else {
                int ttl = st.top().second;
                st.pop();
                ttl++;
                if(ttl < k) st.push({c, ttl});
            }
        }
        string ans;
        while(!st.empty()){
            auto [c, ttl] = st.top();
            st.pop();
            ans += string(ttl, c);
        }
        reverse(begin(ans), end(ans)); // reverse the string to get the correct order
        return ans;
    }
};