#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) {
            return 0;
        }
        int min_left = prices[0];
        int max_profit = profit_right(prices, 1);
        for (int i = 1; i < prices.size(); i++) {
            min_left = min(min_left, prices[i-1]);
            if ((i == 0 && prices[i] >= prices[i+1])
                    || (i+1 == prices.size() && prices[i] >= prices[i-1])
                    || (i+1 < prices.size() && prices[i] >= prices[i-1] && prices[i] >= prices[i+1])) {
                int profit = prices[i] - min_left + profit_right(prices, i+1);
                if (profit > max_profit) {
                    max_profit = profit;
                }
            }
        }
        return max_profit;
    }

    int profit_right(vector<int>& prices, int start) {
        if (start >= prices.size()) {
            return 0;
        }
        int dp = 0;
        int min_left = prices[start];
        for (int i = start+1; i < prices.size(); i++) {
            min_left = min(min_left, prices[i-1]);
            dp = max(dp, prices[i] - min_left);
        }
        return dp;
    }
};

int main()
{
    vector<int> input = {8,3,6,2,8,8,8,4,2,0,7,2,9,4,9};
    Solution s;
    cout << s.maxProfit(input) << endl;
    return 0;
}