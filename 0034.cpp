class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0) {
            return {-1, -1};
        }
        int start = find_start(nums, target);
        if (start == -1) {
            return {-1, -1};
        }
        int end = find_end(nums, target);
        return {start, end};
    }

    int find_start(vector<int>& nums, int target) {
        int start = -1;
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) { 
            int mid = (left + right) / 2;
            if (nums[mid] == target) {
                if (start == -1 || mid < start) {
                    start = mid;
                }
                right = mid - 1;                
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return start;
    }

    int find_end(vector<int>& nums, int target) {
        int end = -1;
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) {
                if (end == -1 || mid > end) {
                    end = mid;
                }
                left = mid + 1;               
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return end;
    }
};