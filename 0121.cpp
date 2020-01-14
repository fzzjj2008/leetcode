class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) {
            return 0;
        }
        int dp = 0;
        int min_left = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            min_left = min(min_left, prices[i-1]);
            dp = max(dp, prices[i]-min_left);
        }
        return dp;
    }
};