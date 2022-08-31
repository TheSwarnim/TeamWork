class Solution {
public:
    typedef vector<int> vi;
    typedef vector<vi> vvi;
    
    vi dir = {0, 1, 0, -1, 0};
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& mat) {
        vvi res;
        int n = mat.size(), m = mat[0].size();
        vvi pacific(n, vi(m));
        vvi atlantic(n, vi(m));
        queue<vi> pq, aq;
        
        for(int i = 0; i < n; i++){
            pq.push({i, 0});
            aq.push({i, m-1});
            pacific[i][0] = 1;
            atlantic[i][m-1] = 1;
        }
        for(int j = 0; j < m; j++){
            pq.push({0, j});
            aq.push({n-1, j});
            pacific[0][j] = 1;
            atlantic[n-1][j] = 1;
        }
        
        bfs(mat, pacific, pq);
        bfs(mat, atlantic, aq);
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(pacific[i][j] && atlantic[i][j]){
                    res.push_back({i, j});
                }
            }
        }
        
        return res;
    }
    
    void bfs(vvi &matrix, vvi &visited, queue<vi> &q){
        int n = matrix.size(), m = matrix[0].size();
        while(!q.empty()){
            auto curr = q.front();
            int x = curr[0], y = curr[1];
            q.pop();
            
            for(int d = 0; d < 4; d++){
                int i = x + dir[d], j = y + dir[d+1];
                if(i < 0 or j < 0 or i >= n or j >= m or visited[i][j] or matrix[i][j] < matrix[x][y]){
                    continue;
                }
                visited[i][j] = 1;
                q.push({i, j});
            }
        }
    }
};