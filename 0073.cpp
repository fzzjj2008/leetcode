class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (m == 0) {
            return;
        }
        int n = matrix[0].size();
        if (n == 0) {
            return;
        }
        bool row0 = false;
        bool col0 = false;
        //把存在0的行和列归并到第一行和第一列中
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    if (i == 0)    row0 = true;
                    if (j == 0)    col0 = true;
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        //根据第一行和第一列清0
        for (int i = 1; i < m; i++) {
            if (matrix[i][0] == 0) {
                for (int j = 1; j < n; j++) {
                    matrix[i][j] = 0;
                }
            }
        }
        for (int j = 1; j < n; j++) {
            if (matrix[0][j] == 0) {
                for (int i = 1; i < m; i++) {
                    matrix[i][j] = 0;
                }
            }
        }
        //清除第一行和第一列
        if (row0 == true) {
            for (int j = 0; j < n; j++) {
                matrix[0][j] = 0;
            }
        }
        if (col0 == true) {
            for (int i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};