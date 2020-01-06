class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (m == 0) {
            return false;
        }
        int n = matrix[0].size();
        if (n == 0) {
            return false;
        }
        int x = m - 1;
        int y = 0;
        while (x >= 0 && x < m && y >= 0 && y < n) {
            if (matrix[x][y] == target) {
                return true;
            } else if (matrix[x][y] > target) {
                x--;
            } else {
                y++;
            }
        }
        return false;
    }
};