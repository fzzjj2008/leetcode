class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        if (nums.size() == 0) {
            return 0;
        }
        if (nums[left] > target) {
            return 0;
        }
        if (nums[right] < target) {
            return nums.size();
        }

        while (left < right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};