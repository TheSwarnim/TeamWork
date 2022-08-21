class Solution {
public:
    using ll = long long;
    long long kSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<ll> ans;
        priority_queue<pair<ll, ll>> pq;
        ll sum = 0;
        for(int i = 0; i < n; i++){
            sum += nums[i] > 0 ? nums[i] : 0;
            nums[i] = abs(nums[i]);
        }
        
        sort(begin(nums), end(nums));
        pq.push({sum - nums[0], 0});
        ans.push_back(sum);
        while(ans.size() < k){
            auto [val, index] = pq.top();
            pq.pop();
            ans.push_back(val);
            if(index + 1 < n){
                pq.push({val+nums[index] - nums[index+1], index+1});
                pq.push({val-nums[index+1], index+1});
            }
        }
        return ans[k-1];
   }
};