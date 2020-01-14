class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.size() == 0) {
            return 0;
        }
        for (int i = 1; i < triangle.size(); i++) {
            for (int j = i; j>=0; j--) {
                if (j == 0) {
                    triangle[i][j] += triangle[i-1][j];
                } else if (j == i) {
                    triangle[i][j] += triangle[i-1][j-1];
                } else {
                    triangle[i][j] += min(triangle[i-1][j-1], triangle[i-1][j]);
                }
            }
        }
        int min_sum = triangle[triangle.size()-1][0];
        for (int i = 1; i < triangle.size(); i++) {
            if (triangle[triangle.size()-1][i] < min_sum) {
                min_sum = triangle[triangle.size()-1][i];
            }
        }
        return min_sum;
    }
};