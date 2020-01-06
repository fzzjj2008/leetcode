class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 2) {
            return nums.size() ;
        }
        int slow_pointer = 1;
        int last_num = nums[0];
        int count = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == last_num) {
                count++;
                if (count > 2) {
                    continue;
                }
            } else {
                count = 1;
                last_num = nums[i];
            }
            nums[slow_pointer++] = nums[i];
        }
        return slow_pointer;
    }
};