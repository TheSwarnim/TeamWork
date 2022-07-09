class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> ans;
        int i, j;
        vector<int> cnt(101,0);
        //keep a count of each element in cnt vector
        for(i = 0; i < nums.size(); i++) {
            cnt[nums[i]]++;
        }
        //keep continuos cnt of element smaller than to particular number
        for(i = 1; i < 101; i++) {
            cnt[i] += cnt[i - 1];
        }
        
        //insert the cnt of each element into ans;
        for(i = 0; i < nums.size(); i++) {
            if(nums[i] == 0)  //edge case if nums[i] = 0
                ans.push_back(0);
            else
                ans.push_back(cnt[nums[i] - 1]);  // add cnt of number smaller to it.
                
        }
        return ans;
    }
};