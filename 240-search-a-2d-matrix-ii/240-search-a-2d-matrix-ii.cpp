class Solution {
public:
    #define all(c) (c).begin(), (c).end()
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i = 0; i < matrix.size(); i++){
            auto it = lower_bound(all(matrix[i]), target);
            if(it != end(matrix[i])){
                int idx = it - begin(matrix[i]);
                if(matrix[i][idx] == target) return true;
                // else continue;
            }
        }
        return false;
    }
};