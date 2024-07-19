class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty() || board[0].empty()) return false;
        
        int m = board.size();
        int n = board[0].size();
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dfs(board, word, 0, i, j)) {
                    return true;
                }
            }
        }
        
        return false;
    }

private:
    bool dfs(vector<vector<char>>& board, string& word, int index, int x, int y) {
        if (index == word.size()) return true;
        
        int m = board.size();
        int n = board[0].size();
        
        if (x < 0 || x >= m || y < 0 || y >= n || board[x][y] != word[index]) {
            return false;
        }
        
        char temp = board[x][y];
        board[x][y] = '#'; // Mark as visited
        
        bool found = dfs(board, word, index + 1, x + 1, y) ||
                     dfs(board, word, index + 1, x - 1, y) ||
                     dfs(board, word, index + 1, x, y + 1) ||
                     dfs(board, word, index + 1, x, y - 1);
        
        board[x][y] = temp; // Restore the original value
        
        return found;
    }
};
