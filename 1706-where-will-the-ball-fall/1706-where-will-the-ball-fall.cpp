class Solution {
public:
    int dfs(vector<vector<int>> &grid, int i, int j){
        if(i == grid.size()){
            return j;
        }
        
        // left to right
        if(grid[i][j] == 1 && j+1 < grid[0].size() && grid[i][j+1] == 1){
            return dfs(grid, i+1, j+1);
        } 
        // right to left
        else if(grid[i][j] == -1 && j-1 >= 0 && grid[i][j-1] == -1){
            return dfs(grid, i+1, j-1);
        } else {
            return -1;
        }
    }
    
    vector<int> findBall(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<int> res(col);
        for(int j = 0; j < col; j++){
            res[j] = dfs(grid, 0, j);
        }
        return res;
    }
};