class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size();
        while (left < right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[left] <= nums[mid]) {
                //前半部分有序
                if (target >= nums[left] && target <= nums[mid]) {
                    //target在[left,mid]之间
                    right = mid;
                } else {
                    //target在后半部分
                    left = mid + 1;
                }
            } else {
                //前半部分无序
                if (target >= nums[left] || target <= nums[mid]) {
                    //target在[left,mid]之间
                    right = mid;
                } else {
                    left = mid + 1;
                }
            }
        }
        return -1;
    }
};