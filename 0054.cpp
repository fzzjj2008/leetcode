class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int m = matrix.size();
        if (m == 0) {
            return result;
        }
        int n = matrix[0].size();
        if (n == 0) {
            return result;
        }

        int x = 0, y = 0;
        int wrap = 0;
        while (1) {
            //right
            if (wrap > n-wrap-1)    break;
            for (y=wrap; y <= n-wrap-1; y++) {
                result.push_back(matrix[wrap][y]);
            }
            //down
            if (wrap + 1 > m-wrap-1)    break;
            for (x=wrap + 1; x <= m-wrap-1; x++) {
                result.push_back(matrix[x][n-1-wrap]);
            }
            //left
            if (wrap > n-2-wrap)    break;
            for (y=n-2-wrap; y >= wrap; y--) {
                result.push_back(matrix[m-1-wrap][y]);
            }
            //up
            if (wrap+1 > m-2-wrap)    break;
            for (x=m-2-wrap; x >= wrap + 1; x--) {
                result.push_back(matrix[x][wrap]);
            }
            wrap++;
        }
        return result;
    }
};