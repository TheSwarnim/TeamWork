class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(begin(nums), end(nums));
        
        int n = nums.size();
        int res, diff = INT_MAX;
        for(int i = 0; i < n; i++){
            int j = i+1, k = n-1;
            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];
                if(abs(target - sum) < diff){
                    diff = abs(target - sum);
                    res = sum;
                    // cout << target << " " << sum << " " << res << " " << abs(target - sum) << endl;
                }
                if(sum == target){
                    return target;
                } else if(sum < target){
                    j++;
                } else {             
                    k--;
                }
            }
        }
        
        return res;
    }
};