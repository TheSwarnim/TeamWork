class Solution {
public:
    bool exit(vector<int> &entrance, int x, int y, int n, int m){
        if(!(x == entrance[0] && y == entrance[1]) && (x == 0 || y == 0 || (x == n-1) || (y == m-1))){
            return true;
        }
        return false;
    }
    
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        queue<pair<int, int>> q;
        q.push({entrance[0], entrance[1]});
        int moves = 0;
        
        while(!q.empty()){
            int size = q.size();
            while(size-- > 0){
                auto [x, y] = q.front(); q.pop();
            
                if(maze[x][y] == '+') {
                    continue;
                }

                if(exit(entrance, x, y, maze.size(), maze[0].size())){
                    return moves;
                }
                
                maze[x][y] = '+';
                
                for(int d = 0; d < 4; d++){
                    int i = x + dir[d];
                    int j = y + dir[d+1];
                    
                    if(i >= 0 && j >= 0 && i < maze.size() && j < maze[0].size() && maze[i][j] == '.') {
                        q.push({i, j});
                    }
                }
            }
            moves++;
        }
        
        return -1;
    }
    
    vector<int> dir = {0, 1, 0, -1, 0};
};