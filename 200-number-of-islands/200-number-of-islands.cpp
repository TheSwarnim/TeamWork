class Solution {
public:
    void dfs(vector<vector<char>> &grid, int x, int y, int n, int m){
        if(x < 0 || y < 0 || x >= n || y >= m || grid[x][y] == '0'){
            return;
        }
        
        vector<int> dir = {0, 1, 0, -1, 0};
        grid[x][y] = '0';
        for(int d = 0; d < 4; d++){
            int i = x + dir[d];
            int j = y + dir[d+1];
            dfs(grid, i, j, n, m);
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int ttlIslands = 0;
        
        int n = grid.size(), m = grid[0].size();
        for(int i  = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == '1'){
                    dfs(grid, i, j, n, m);
                    ttlIslands++;
                }
            }
        }
        
        return ttlIslands;
    }
};