class Solution {
public:
    int getNumOfLives(int m, int n, const vector<vector<int>> &board){
        int cnt = 0;
        for(int i = m - 1; i <= m + 1; ++i){
            if(i < 0 || i >= board.size()) continue;
            for(int j = n - 1; j <= n + 1; ++j){
                if(j < 0 || j >= board[0].size() || (i == m && j == n)) continue;
                if(board[i][j] > 0) cnt++;
            }
        }
        return cnt;
    }
    void gameOfLife(vector<vector<int>>& board) {
        if(board.empty()) return;
        for(int i = 0; i < board.size(); ++i){
            for(int j = 0; j < board[0].size(); ++j){
                int lives = getNumOfLives(i, j, board) + 1;
                board[i][j] = board[i][j] == 0 ? -lives : lives;
            }
        }
        for(int i = 0; i < board.size(); ++i){
            for(int j = 0; j < board[0].size(); ++j){
                if(board[i][j] == 3 || abs(board[i][j]) == 4)
                    board[i][j] = 1;
                else
                    board[i][j] = 0;
            }
        }
    }
};
