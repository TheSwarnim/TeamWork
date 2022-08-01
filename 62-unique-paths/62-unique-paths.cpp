class Solution {
public:
    int res = 0;
    int mat[101][101];
    int uniquePaths(int m, int n) {
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i ==0 || j == 0){
                    mat[i][j] = 1;
                } else {
                    mat[i][j] = mat[i-1][j] + mat[i][j-1];
                }
            }
        }
        return mat[m-1][n-1];
    }
};