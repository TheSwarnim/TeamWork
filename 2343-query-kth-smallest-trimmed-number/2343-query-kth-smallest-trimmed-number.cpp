class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), strsize = nums[0].size();
        // the approach is to pre calculate early and give answer as per the queries as per the index required
        unordered_map<int, vector<pair<string, int>>> lis;
        
        vector<int> ans;
        for(auto &q : queries){
            int k = q[0], trim = q[1];
            if(lis.find(trim-1) == lis.end())
                calcForIthIndex(lis, trim-1, strsize, nums); 
            ans.push_back(lis[trim-1][k-1].second);
        }
        return ans;
    }
    
    void calcForIthIndex(unordered_map<int, vector<pair<string, int>>> &lis, int idx, int strsize, vector<string>& nums){
        for(int j = 0; j < nums.size(); j++){
            string substr = nums[j].substr(strsize-1-idx);
            lis[idx].push_back({substr, j});
        }
        
        auto &l = lis[idx];
        
        // time to sort the array
        sort(begin(l), end(l), [&](pair<string, int> &a, pair<string, int> &b){
            // cout << a.first << " " << b.first << " " << a.second << " " << b.second << endl;
            string &s1 = a.first, &s2 = b.first;
            return s1 == s2 ? a.second < b.second : s1.compare(s2) < 0; 
        });
    }
};