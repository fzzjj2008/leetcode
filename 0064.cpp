class Solution {
public:
    //dp[x][y] = min(sum[x-1][y], sum[x][y-1]) + grid[x][y]
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        if (m == 0) {
            return 0;
        }
        int n = grid[0].size();
        if (n == 0) {
            return 0;
        }
        vector<int> dp = vector<int>(n,grid[0][0]);
        for (int j = 1; j < n; j++) {
            dp[j] = dp[j-1] + grid[0][j];
        }
        int head = grid[0][0];
        for (int i = 1; i < m; i++) {
            head += grid[i][0];
            int tmp_sum = head;
            for (int j = 1; j < n; j++) {
                dp[j] = min(tmp_sum, dp[j]) + grid[i][j];
                tmp_sum = dp[j];
            }
        }
        return dp[n - 1];
    }
};