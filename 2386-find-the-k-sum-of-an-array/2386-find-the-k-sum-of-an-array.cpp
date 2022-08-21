class Solution {
public:
    using ll = long long;
    long long kSum(vector<int>& nums, int k) {
        vector<ll> ans;
        priority_queue<pair<ll, ll>> pq;
        ll n = nums.size(), sum = 0;
        for(int &x : nums){
            sum += x > 0 ? x : 0;
            x = abs(x);
        }
        sort(begin(nums), end(nums));
        ans.push_back(sum);
        pq.push({sum-nums[0], 0});
        while(ans.size() < k){
            auto [nextSum, i] = pq.top(); pq.pop();
            ans.push_back(nextSum);
            if(i+1 < n){
                pq.push({nextSum - nums[i+1], i+1});
                pq.push({nextSum - nums[i+1] + nums[i], i+1});
            }
        }
        return ans[k-1];
    }
};