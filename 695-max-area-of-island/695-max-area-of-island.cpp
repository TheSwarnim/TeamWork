class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                    res = max(res, dfs(grid, i, j));
                }
            }
        }
        return res;
    }
    
    int dfs(vector<vector<int>> &grid, int i, int j){
        int ttl = 1;
        grid[i][j] = 0;
        for(int d = 0; d < 4; d++){
            int x = i + dir[d];
            int y = j + dir[d+1];
            if(x < 0 || y < 0 || x >= grid.size() || 
               y >= grid[0].size() || grid[x][y] == 0) 
                continue;
            ttl += dfs(grid, x, y);
        }
        return ttl;
    }
    
    vector<int> dir = {0, 1, 0, -1, 0};
};