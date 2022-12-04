class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();
        long left = 0, right = accumulate(begin(nums), end(nums), 0l);
        int avg = INT_MAX, idx = -1;
        for(int i = 0; i < n; i++){
            left += nums[i];
            right -= nums[i];
            
            int a = left / (i+1);
            int b = (i == n-1) ? 0 : right/(n-i-1);
            
            if( abs(a-b) < avg ) {
                avg = abs(a-b);
                idx = i;
            }
        }
        return idx;
    }
};