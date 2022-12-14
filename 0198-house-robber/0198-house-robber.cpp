class Solution {
public:
    
    unordered_map<int, int> dp;
    int rob(vector<int>& nums, int i = 0) {
        if(i >= nums.size()){
            return 0;
        }
        
        if(dp.find(i) != dp.end()){
            return dp[i];
        }
        
        return dp[i] = max(nums[i] + rob(nums, i+2), rob(nums, i+1));
    }
};