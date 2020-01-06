class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        if (m == 0)    return false;
        n = board[0].size();
        if (n == 0)    return false;
        this->board = board;
        this->word = word;
        vector<vector<bool>> travel(m, vector<bool>(n, false));
        this->travel = travel;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (exist_word(i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool exist_word(int x, int y, int i) {
        if (x < 0 || x >= m || y < 0 || y >= n)   return false;
        if (travel[x][y] == true)                 return false;
        if (board[x][y] != word[i])               return false;
        if (i == word.length() - 1)               return true;

        travel[x][y] = true;
        if (exist_word(x - 1, y, i + 1))          return true;
        if (exist_word(x + 1, y, i + 1))          return true;
        if (exist_word(x, y - 1, i + 1))          return true;
        if (exist_word(x, y + 1, i + 1))          return true;
        travel[x][y] = false;

        return false;
    }
private:
    vector<vector<char>> board;
    vector<vector<bool>> travel;
    int m;
    int n;
    string word;
};