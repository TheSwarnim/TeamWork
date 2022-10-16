class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long res = 0, mini = -1, maxi = -1;
        for(int i = 0, j = 0; j < nums.size(); j++){
            if(nums[j] > maxK || nums[j] < minK){
                mini = maxi = -1;
                i = j+1;
            }
            if(nums[j] == minK) mini = j;
            if(nums[j] == maxK) maxi = j;
            res += max(0ll, min(mini, maxi) - i + 1);
        }
        return res;
    }
};