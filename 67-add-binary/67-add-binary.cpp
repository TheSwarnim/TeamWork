class Solution {
public:
    string addBinary(string a, string b) {
        reverse(begin(a), end(a));
        reverse(begin(b), end(b));
        
        int carry = 0, i = 0, j = 0, n = a.length(), m = b.length();
        
        string res;
        
        while(carry > 0 || i < n || j < m){
            if(i < n){
                carry += a[i++] - '0';
            }
            if(j < m){
                carry += b[j++] - '0';
            }
            
            res += to_string(carry%2);
            if(carry >= 2){
                carry = 1;
            } else {
                carry = 0;
            }
        }
        
        reverse(begin(res), end(res));
        
        return res;
    }
};