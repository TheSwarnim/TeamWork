class Solution {
public:
    /*
    the question is almost similar to subarray sum with given target
    to do the same with this question, we create a window of vertical 
    like belo on a sliding window where we calculate horizontal
    prefix rowwise(similar to subarray sum) and repeat this in 2d
          ij
    k=0 --**---
    k=1 --**---
    k=2 --**---
    k=3 --**---
    ... -------
    ... -------

    */
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        
        for(int i = 0; i < n; i++)
            for(int j = 1; j < m; j++)
                matrix[i][j] += matrix[i][j-1];
        
        int res = 0;
        unordered_map<int, int> mp;
        for(int y1 = 0; y1 < m; y1++)
            for(int y2 = y1; y2 < m; y2++){
                mp = {{0, 1}};
                int sum = 0;
                for(int x = 0; x < n; x++){
                    sum += matrix[x][y2] - (y1 > 0 ? matrix[x][y1-1] : 0);
                    res += mp[sum-target];
                    mp[sum]++;
                }
            }
        return res;
    }
};