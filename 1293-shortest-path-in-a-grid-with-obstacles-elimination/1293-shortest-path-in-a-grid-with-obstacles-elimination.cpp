class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        
        bool visited[n][m][k+1];
        memset(visited, 0, sizeof(visited));
        
        queue<tuple<int, int, int>> q; // x,y,kused
        q.push({0, 0, k});
        
        int res = 0;
        
        while(!q.empty()){
            
            int size = q.size();
            while(size-- > 0){
                
                auto [x,y,kk] = q.front(); q.pop();
                
                // if visited then return
                if(visited[x][y][kk]){
                    continue;
                }
                visited[x][y][kk] = true;
                
                // if last corner then return
                if(x == n-1 && y == m-1){
                    return res;
                }
                
                kk -= grid[x][y];
                // kk is neg then it means we can't proceed
                if(kk < 0){
                    continue;
                }
                
                for(int d = 0; d < 4; d++){
                    int i = x + dir[d];
                    int j = y + dir[d+1];
                    
                    if(i >= 0 && j >= 0 && i < n && j < m){
                        q.push({i, j, kk});
                    }
                }
            }
            
            res++;
        }
        
        return -1;
    }
    
    vector<int> dir = {0, 1, 0, -1, 0};
};