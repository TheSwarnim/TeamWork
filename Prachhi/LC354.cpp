class Solution {
public:
   
    //ALGO USED: Longest Increasing Subsequence (DP Problem)
    static bool cmp(vector<int> &a, vector<int> &b){
        if (a[0] == b[0])  
            return a[1] > b[1];
        return a[0] < b[0];
    }
    int maxEnvelopes(vector<vector<int>>& e) {
        // sort the envelope according to increasing order of width
        sort(e.begin(), e.end(),cmp);
        int n = e.size();
        vector<int> dp;
        
        //Now we can put the envelope onto another if its height is greater to previous height
        //lower_bound and the longest increasing subsequence of height.
        for(int i=0;i<n;i++){
            auto itr = lower_bound(dp.begin(), dp.end(), e[i][1]);
            if(itr == dp.end())
                dp.push_back(e[i][1]);
            else
                *itr = e[i][1]; 
        }
        
        return dp.size();
    }
};