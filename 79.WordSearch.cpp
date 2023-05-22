class Solution {
public:
    int n, m, len;
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        len = word.size();
        vector<vector<bool>> visit(m, vector<bool>(n, false));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == word[0]){
                    visit[i][j] = true;
                    if(dfs(board, word, i, j, 0, visit)){
                        return true;
                    }
                    visit[i][j] = false;
                }
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>>& board, string& word, int x, int y, int index, vector<vector<bool>>& visit){
        if(index == len - 1){
            return true;
        } else {
            if(x+1 < m && board[x+1][y] == word[index+1] && !visit[x+1][y]){
                visit[x+1][y] = true;
                if(dfs(board, word, x+1, y, index+1, visit))
                    return true;
                visit[x+1][y] = false;
            }
            if(x-1 >= 0 && board[x-1][y] == word[index+1] && !visit[x-1][y]){
                visit[x-1][y] = true;
                if(dfs(board, word, x-1, y, index+1, visit))
                    return true;
                visit[x-1][y] = false;
            }
            if(y+1 < n && board[x][y+1] == word[index+1] && !visit[x][y+1]){
                visit[x][y+1] = true;
                if(dfs(board, word, x, y+1, index+1, visit))
                    return true;
                visit[x][y+1] = false;
            }
            if(y-1 >= 0 && board[x][y-1] == word[index+1] && !visit[x][y-1]){
                visit[x][y-1] = true;
                if(dfs(board, word, x, y-1, index+1, visit))
                    return true;
                visit[x][y-1] = false;
            }
            return false;
        }
    }
};
