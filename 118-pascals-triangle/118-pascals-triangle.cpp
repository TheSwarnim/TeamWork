class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> ans = {{1}};
        for(int i = 2; i <= n; i++){
            int size = ans.back().size()+1;
            vector<int> tempCnt(size);
            tempCnt[0] = 1;
            for(int j = 0; j < ans.back().size()-1; j++){
                tempCnt[j+1] = ans.back()[j] + ans.back()[j+1];
            }
            tempCnt[size-1] = 1;
            ans.push_back(tempCnt);
        }
        return ans;
    }
};