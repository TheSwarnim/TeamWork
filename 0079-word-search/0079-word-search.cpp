class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); i++){
            for(int j = 0;j < board[0].size(); j++){
                if(board[i][j] == word[0] && findWord(board, word, 0, i, j)) {
                    return true;
                }
            }
        }
        return false;
    }
    
    bool findWord(vector<vector<char>> &board, string &word, int idx, int x, int y) {  
        if(++idx == word.size()) {
            return true;
        }

        char c = board[x][y];
        board[x][y] = '$';        
        
        for(int d = 0; d < 4; d++){
            int i = x + dir[d];
            int j = y + dir[d+1];
            
            if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || ( idx != word.size() && board[i][j] != word[idx])) {
                continue;
            }
            
            if(findWord(board, word, idx, i, j)) {
                board[x][y] = c;
                return true;
            }
        }
        
        board[x][y] = c;
        
        return false;
    }
    
    vector<int> dir = {0,1,0,-1,0};
};