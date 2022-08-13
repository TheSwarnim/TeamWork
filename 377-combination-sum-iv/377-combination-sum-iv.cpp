class Solution {
public:
    
    unordered_map<int, int> dp;
    int rec(vector<int> &nums, int tar){
        if(tar == 0) return 1;
        
        if(dp.find(tar) != dp.end()){
            return dp[tar];
        }
        
        int ttl = 0;
        for(int i = 0; i < nums.size(); i++){
            if(tar >= nums[i]){
                ttl += rec(nums, tar - nums[i]);
            }
        }
        
        return dp[tar] = ttl;
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        sort(begin(nums), end(nums));
        
        return rec(nums, target);
    }
};