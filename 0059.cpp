class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result;
        for (int i = 0; i < n; i++) {
            vector<int> line;
            for (int j = 0; j < n; j++) {
                line.push_back(0);
            }
            result.push_back(line);
        }

        int i = 1;
        int x, y;
        int wrap = 0;
        while (i <= n * n) {
            //right
            for (y = wrap; y < n - wrap; y++) {
                result[wrap][y] = i++;
            }
            //down
            for (x = wrap + 1; x < n - wrap; x++) {
                result[x][n-1-wrap] = i++;
            }
            //left
            for (y = n-2-wrap; y >= wrap; y--) {
                result[n-1-wrap][y] = i++;
            }
            //up
            for (x = n-2-wrap; x > wrap; x--) {
                result[x][wrap] = i++;
            }
            wrap++;
        }
        return result;
    }
};