class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        
        for(int i=0; i <board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(board[i][j]!=word[0])
                    continue;
                if(my_dfs(i, j, 0, word, board))
                    return true;
            }
        }
        return false;
    }
    bool my_dfs(int i, int j, int k, string word, vector<vector<char>>& board){
        int row = board.size();
        int col = board[0].size();
        // 邊界條件
        if(i<0 || j<0 || j>=col || i>=row)
            return false;
        char tmp = board[i][j];

        if(tmp!=word[k]){
            return false;
        }else if(k == (word.size()-1))
            return true;
        // 若符合word[k] 則將原始位置替換為*代表走過並繼續遞迴
        board[i][j] = '*';

        
        if(my_dfs(i,j+1, k+1, word, board) || my_dfs(i+1,j, k+1, word, board) || my_dfs(i,j-1, k+1, word, board) || my_dfs(i-1,j, k+1, word, board))
            return true;
        // 若上述沒有達成true條件，則將原始位置改回來
        board[i][j] = tmp;
        return false;
        
    }
};
