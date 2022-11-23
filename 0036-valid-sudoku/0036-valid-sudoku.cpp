class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        
        cout << "checking row wise\n";
        for(int i = 0; i < n; i++){
            unordered_map<char, int> cnt;
            for(int j = 0; j < n; j++){
                if(board[i][j] != '.' && ++cnt[board[i][j]] > 1) {
                    cout << i << " " << j << endl;
                    return false;
                }
            }
        }
        
        cout << "checking column wise\n";
        for(int i = 0; i < n; i++){
            unordered_map<char, int> cnt;
            for(int j = 0; j < n; j++){
                if(board[j][i] != '.' && ++cnt[board[j][i]] > 1) {
                    cout << i << " " << j << endl;
                    return false;
                }
            }
        }
        
        cout << "checking for 3*3 sub-boxes" << endl;
        // check for 3*3 sub-boxes
        for(int x = 0; x < 3; x++){
            for(int y = 0; y < 3; y++){
                unordered_map<char, int> cnt;
                for(int i = 0; i < 3; i++){
                    for(int j = 0; j < 3; j++){
                        if(board[x*3 + i][y*3 + j] != '.' && ++cnt[board[x*3 + i][y*3 + j]] > 1){
                            cout << i << " " << j << endl;
                            return false;
                        }
                    }
                }
            }
        }
        
        return true;
    }
};