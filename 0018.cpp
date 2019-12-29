class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        int len = nums.size();
        if (len < 4) {
            return result;
        }
        sort(nums.begin(), nums.end());
        for (int left_1 = 0; left_1 < len - 3; left_1++) {
            //cut
            if (nums[left_1] * 4 > target) {
                break;
            }
            if (left_1 > 0 && nums[left_1] == nums[left_1 - 1]) {
                continue;
            }
            for (int left_2 = left_1 + 1; left_2 < len - 2; left_2++) {
                //cut
                if (nums[left_1] + nums[left_2] * 3 > target) {
                    break;
                }
                if (left_2 - 1 > left_1 && nums[left_2] == nums[left_2 - 1]) {
                    continue;
                }
                check_sum(nums, result, target, left_1, left_2);
            }
        }
        return result;
    }

    void check_sum(vector<int>& nums, vector<vector<int>>& result, int target, int left_1, int left_2) {
        int mid = left_2 + 1;
        int right = nums.size() - 1;

        while (mid < right) {
            if (mid-1 > left_2 && nums[mid-1] == nums[mid]) {
                mid++;
                continue;
            }
            if (right+1 < nums.size() && nums[right] == nums[right + 1]) {
                right--;
                continue;
            }
            int ret = nums[left_1] + nums[left_2] + nums[mid] + nums[right] - target;
            if (ret == 0) {
                result.push_back({nums[left_1], nums[left_2], nums[mid], nums[right]});
                mid++;
                right--;
            } else if (ret < 0) {
                mid++;
            } else {
                right--;
            }
        }
    }
};