class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int edge = matrix.size();
        for (int i = 0; i < (edge + 1) / 2; i++) {
            for (int j = 0; j < edge / 2; j++) {
                int t = matrix[i][j];
                matrix[i][j] = matrix[edge - 1 - j][i];
                matrix[edge - 1 - j][i] = matrix[edge - 1 - i][edge - 1 - j];
                matrix[edge - 1 - i][edge - 1 - j] = matrix[j][edge - 1 - i];
                matrix[j][edge - 1 - i] = t;
            }
        }
    }
};