class Solution {
public:
    // Keep a stack for simulation
    //first push the current element into stack 
    //Check whether the top element of stack is equal to current element of popped
    //if true keep popping the element and increment the counter of popped vector
    //at last check if stack is empty or not
    //if empty the push and popped sequence are a possible sequence
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int n= pushed.size(), j = 0;
        for(int i=0;i<n;i++){
            st.push(pushed[i]);
            //cout<<st.top()<<" ";
            while(!st.empty() && st.top()==popped[j]){
                st.pop();
                j++;
            }
        }
        return st.empty();
    }
};