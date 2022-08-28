class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        int xini = n-1, xend = n-1, yini = 0, yend = 0;
        while(xend >= 0){
            vector<int> arr;
            for(int i = xini, j = yini; i <= xend; i++, j++){
                arr.push_back(mat[i][j]);
            }
            sort(begin(arr), end(arr));
            int idx = 0;
            for(int i = xini, j = yini; i <= xend; i++, j++){
                mat[i][j] = arr[idx++];
            }
            if(xini > 0) xini--;
            else {
                yini++;
            }
            if(yend < m-1) yend++;
            else {
                xend--;
            }
        }
        return mat;
    }
};