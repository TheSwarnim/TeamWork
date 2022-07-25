class Solution {
public:
    /*
    the question is asking for upper_bound and lower_bound
    1) first method is shortcut one to use both inbuild function
    2) second mtd is to write the binary search code for upper bound and lower bound
    */
    vector<int> searchRange(vector<int>& nums, int target) {
        auto leftIt = lower_bound(begin(nums), end(nums), target);
        
        if(leftIt == end(nums)) return {-1, -1};
        int idx = leftIt - begin(nums);
        if(nums[idx] != target) return {-1, -1};
        
        auto rightIt = upper_bound(begin(nums), end(nums), target);
        
        return {int(leftIt - begin(nums)), int(rightIt - begin(nums) - 1)};
    }
};