class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> left(n), right(n);
        
        stack<int> st;
        for(int i = 0; i < n; i++){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            if(st.empty()){
                left[i] = -1;
            } else {
                left[i] = st.top();
            }
            st.push(i);
        }
        
        stack<int> st2;
        for(int i = n-1; i >= 0; i--){
            while(!st2.empty() && arr[st2.top()] > arr[i]){
                st2.pop();
            }
            if(st2.empty()) {
                right[i] = n;
            } else {
                right[i] = st2.top();
            }
            st2.push(i);
        }
        
        long mod = (1e9 + 7);
        long res = 0;
        
        for(int i = 0; i < n; i++){
            res = (res + ( 1ll*(i-left[i])*(right[i]-i)*arr[i] ) )%mod;
        }
        
        return res;
    }
};