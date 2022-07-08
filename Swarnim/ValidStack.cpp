class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int i = 0, j = 0;
        while(i < pushed.size()){
            st.push(pushed[i]);
            while(j < popped.size() && !st.empty() && st.top() == popped[j]){
                st.pop();
                j++;
            }
            i++; 
        }
        
        return i == pushed.size() && j == popped.size() && st.empty();
    }
};