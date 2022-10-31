class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        
        for(int i = n-1, j = 0; i >= 0; i--){
            for(int ii = i, jj = j; ii < n && jj < m; ii++, jj++){
                if(matrix[ii][jj] != matrix[i][j]){
                    return false;
                }
                // cout << ii << " " << jj << endl;
            }
            
            // cout << endl;
        }
        
        for(int i = 0, j = 0; j < m; j++){
            for(int ii = i, jj = j; ii < n && jj < m; ii++, jj++){
                if(matrix[ii][jj] != matrix[i][j]){
                    return false;
                }
                // cout << ii << " " << jj << endl;
            }
            
            // cout << endl;
        }
        
        return true;
    }
};