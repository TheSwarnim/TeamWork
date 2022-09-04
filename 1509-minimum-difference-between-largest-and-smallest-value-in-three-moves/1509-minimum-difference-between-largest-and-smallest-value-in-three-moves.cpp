class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        if(n <= 3) {
            return 0;
        }
        
        sort(nums.begin(), nums.end());
        int mnndiff = INT_MAX;
        for(int start = 3; start >= 0; start--){
            int left = nums[start];
            int right = nums[n - 1 + start - 3];
            // cout << n + start -4 << endl;
            mnndiff = min(mnndiff, right - left);
        }
        return mnndiff;
    }
};