class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int res = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++){
                if(grid[i][j] != 0){
                    res = max(res, bt(grid, i, j));
                }
            }
        } 
        return res;
    }
                              
    int bt(vector<vector<int>> &grid, int x, int y){
        int val = grid[x][y];
        grid[x][y] = 0;
        
        int ttl = 0;
        for(int d = 0; d < 4; d++){
            int i = x + dir[d];
            int j = y + dir[d+1];
            
            if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0) {
                continue;
            }
            
            ttl = max(ttl, bt(grid, i, j));
        }
        
        grid[x][y] = val;
        return ttl + val;
    }
                              
    int dir[5] = {0, 1, 0, -1, 0};
};