class Solution {
public:
    bool makesquare(vector<int>& nums) {
        int n = nums.size();
        if(n < 4) return false;
        
        int sum = accumulate(begin(nums), end(nums), 0);
        if(sum % 4 != 0) return false;
        
        sort(rbegin(nums), rend(nums));
        
        vector<int> sidesLength(4, 0);
        return bt(nums, sum/4, sidesLength, 0);
    }
    
    bool bt(vector<int> &nums, int target, vector<int> &sidesLength, int idx){
        int n = nums.size();
        
        if(idx == n){
            for(int i = 0; i < 3; i++)
                if(sidesLength[i] != sidesLength[i+1]) 
                    return false;
            return true;
        }
        
        for(int i = 0; i < 4; i++){
            if(sidesLength[i] + nums[idx] > target)
                continue;
            
            sidesLength[i] += nums[idx];
            if(bt(nums, target, sidesLength, idx+1)) return true;
            sidesLength[i] -= nums[idx];
        }
        
        return false;
    }
};