class Solution {
public:
    //dp[0][y] = 1
    //dp[x][0] = 1
    //dp[x][y] = dp[x-1][y] + dp[x][y-1]
    int uniquePaths(int m, int n) {
        vector<int> dp = vector<int>(n, 1);
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[j] = dp[j-1] + dp[j];
            }
        }
        return dp[n-1];
    }
};