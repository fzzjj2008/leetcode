class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int len = nums.size();
        if (len < 3) {
            return result;
        }
        //排序
        sort(nums.begin(), nums.end());
        for (int left = 0; left < len - 2; left++) {
            if (nums[left] < 0) {
                //固定left，保证left+mid+right==0
                //忽略重复的left
                if (left >= 1 && nums[left] == nums[left - 1]) {
                    continue;
                }
                check_sum(nums, len, result, left);
            } else if (nums[left] == 0) {
                //{0,0,0}特殊处理
                if (left+2 < len && nums[left+2] == 0) {
                    result.push_back({0,0,0});
                    break;
                }
            } else {
                //三个数不可能都大于0
                break;
            }
        }

        return result;
    }

    void check_sum(vector<int>& nums, int len, vector<vector<int>>& result, int left) {
        int mid = left + 1;
        int right = len - 1;

        //三个数不可能都小于0
        if (nums[right] < 0) {
            return;
        }

        while (mid < right) {
            //跳过重复的mid
            if (mid - 1 > left && nums[mid] == nums[mid - 1]) {
                mid++;
                continue;
            }
            //跳过重复的right
            if (right + 1 < len && nums[right] == nums[right + 1]) {
                right--;
                continue;
            }
            int sum = nums[mid] + nums[right];
            if (sum == -nums[left]) {
                result.push_back({nums[left], nums[mid], nums[right]});
                mid++;
                right--;
            } else if (sum < -nums[left]) {
                mid++;
            } else {
                right--;
            }
        }

    }
};