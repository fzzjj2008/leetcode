class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i;
        int index = -1;
        //从后往前找到第一个要调整的下标，index左边的数字不变
        for (i = nums.size() - 1; i >= 1; i--) {
            if (nums[i] > nums[i - 1]) {
                index = i - 1;
                break;
            }
        }
        if (index == -1) {
            //未找到，全置换
            reverse(nums, 0);
            return;
        }
        //右侧找比nums[index]大的下一个值，交换
        int min = 0x7fffffff;
        int next_index = 0;
        for (i = index + 1; i < nums.size(); i++) {
            int diff = nums[i] - nums[index];
            if (diff > 0 && diff <= min) {
                min = diff;
                next_index = i;
            }
        }
        swap(nums[index], nums[next_index]);
        
        //置换右侧
        reverse(nums, index + 1);
    }

    void swap(int &a, int &b) {
        int t = a;
        a = b;
        b = t;
    }

    void reverse(vector<int>& nums, int start) {
        for (int i = start, j = nums.size() - 1; i < j; i++, j--) {
            swap(nums[i], nums[j]);
        }
    }
};