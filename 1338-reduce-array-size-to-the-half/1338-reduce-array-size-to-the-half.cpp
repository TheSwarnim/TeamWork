class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> mp;
        for(int x : arr) mp[x]++;
        vector<int> cnt_arr;
        for(auto &p : mp){
            cnt_arr.push_back(p.second);
        }
        sort(rbegin(cnt_arr), rend(cnt_arr));
        int sum = 0, ans = 0, n = arr.size();
        while(sum < n/2){
            sum += cnt_arr[ans++];
        }
        return ans;
    }
};