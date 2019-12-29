class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if (nums.size() < 3) {
            return target;
        }
        sort(nums.begin(), nums.end());
        int min_ret = 0x7fffffff;
        for (int left = 0; left < nums.size() - 2; left++) {
            if (min_ret == 0) {
                return target;
            }
            if (left > 0 && nums[left - 1] == nums[left]) {
                continue;
            }
            int ret = calc_diff(nums, target, left);
            if (abs(ret) < abs(min_ret)) {
                min_ret = ret;
            }
        }
        return (target + min_ret);
    }

    int calc_diff(vector<int>& nums, int target, int left) {
        int mid = left + 1;
        int right = nums.size() - 1;
        int min_ret = 0x7fffffff;

        while (mid < right) {
            if (mid-1 > left && nums[mid-1] == nums[mid]) {
                mid++;
                continue;
            }
            if (right+1 < nums.size() && nums[right] == nums[right+1]) {
                right--;
                continue;
            }
            int ret = nums[left] + nums[mid] + nums[right] - target;
            if (abs(ret) < abs(min_ret)) {
                min_ret = ret;
            }
            //update
            if (ret < 0) {
                mid++;
            } else {
                right--;
            }
        }
        return min_ret;
    }
};