class Solution {
public:
    int numSplits(string s) {
        int n= s.length();
        vector<int> prefix(n), suffix(n);
        unordered_set<char> st;
        for(int i = 0; i < n; i++){
            st.insert(s[i]);
            prefix[i] = st.size();
        }
        st.clear();
        for(int j = n-1; j >= 0; j--){
            st.insert(s[j]);
            suffix[j] = st.size();
        }
        int rs = 0;
        for(int i = 0; i < n-1; i++){
            if(prefix[i] == suffix[i+1]){
                rs++;
            }
        }
        return rs;
    }
};