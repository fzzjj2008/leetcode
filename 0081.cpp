
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) {
                return true;
            } else if (nums[left] < nums[mid]) {
                //左边有序
                if (nums[left] == target) {
                    return true;
                } else if (nums[left] < target && target < nums[mid]) {
                    //搜索左边
                    right = mid - 1;
                } else {
                    //搜索右边
                    left = mid + 1;
                }
            } else if (nums[left] > nums[mid]) {
                //右边有序，左边无序
                if (target == nums[right]) {
                    return true;
                } else if (nums[mid] < target && target < nums[right]) {
                    //搜索右边
                    left = mid + 1;
                } else {
                    //搜索左边
                    right = mid - 1;
                }
            } else {
                left++;
            }
        }
        return false;
    }
};