class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 1, j = 1;
        for(; j < nums.size(); j++){
            if(nums[j-1] == nums[j]) {
                continue;
            } else {
                nums[i++] = nums[j];
            }
        }
        return i;
    }
};