class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        if (len == 0) {
            return 0;
        }
        int max_sum = nums[0];
        int tmp = max_sum;
        for (int i = 1; i < len; i++) {
            tmp = max(nums[i], tmp + nums[i]);
            max_sum = max(max_sum, tmp);
        }
        return max_sum;
    } 
};