class Solution {
public:
    // just store the max digit for each sum of digits and then compare with the current digit
    // if we already have a current max digit, we compare res with the new one
    // otherwise, we store the max digit for that sum of digit in our d_n array
    int maximumSum(vector<int>& nums) {
        int res = -1, d_n[82] = {}; // as max sum of digits can't exceed 81(given in constraint)
        for(int n : nums){
            int d = 0;
            for(int nn = n; nn > 0; nn /= 10)
                d += nn%10;
            if(d_n[d] != 0)
                res = max(res, d_n[d] + n); // comparing the res
            // storing the max d_n
            d_n[d] = max(d_n[d], n);
        }
        return res;
    }
};