class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        /* brute force
        int sum = 0, n = nums.size();
        for(int i = 1; i < n; i++){
            sum = 0;
            for(int j = 0; j < n; j++){
                sum += nums[j];
                if(j == i){
                    if(sum%k == 0){
                        return true;
                    }
                } else if(j > i){
                    sum -= nums[j - i - 1];
                    if(sum%k == 0){
                        return true;
                    }
                }
            }
        }
        return false;
        */
        
        unordered_map<int, int> mp;
        mp[0] = -1;
        int runningSum = 0;
        for(int i = 0; i < nums.size(); i++){
            runningSum += nums[i];
            runningSum %= k;
            if(mp.find(runningSum) != mp.end()){
                if(i - mp[runningSum] > 1) {
                    return true;
                }
            } else {
                mp[runningSum] = i;
            }
        }
        
        return false;
    }
};