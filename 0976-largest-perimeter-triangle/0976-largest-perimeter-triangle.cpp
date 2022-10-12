class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int res = 0;
        for(int i = 0; i <= nums.size()-3; i++){
            if(nums[i]+nums[i+1] > nums[i+2]){
                res = nums[i] + nums[i+1] + nums[i+2];
            }
        }
        return res;
    }
};