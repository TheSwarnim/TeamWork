class Solution {
public:
    //LOGIC: 
    //If the next character vh is same as the last one, increment the current count.
    //Pop the prev count and push the current count
    //Otherwise push a pair (c, 1) into the stack.

    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> st;  // to store char and freq
        st.push({s[0],1});
        int n = s.length();
        
        for(int i=1;i<n;i++){
            if(st.empty())             // edge case if the stack is empty
                st.push({s[i], 1});
            else{
                auto tp = st.top();
                if(s[i]==tp.first){
                    st.pop();
                    int ncnt = tp.second + 1;
                    if(ncnt < k)
                        st.push({s[i], tp.second + 1});
                }
                else
                    st.push({s[i],1});
            }
        }
        
        string ans = "";
        while(!st.empty()) {           //Now pop and store the characters
            auto tp = st.top();
            for(int i=0;i<tp.second;i++)
                ans+=tp.first;
            st.pop();
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
    
};