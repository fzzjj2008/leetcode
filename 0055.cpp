class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() == 0) {
            return true;
        }
        int final_pos = nums.size() - 1;
        int pos = nums[0];
        for (int i = 0; i <= pos; i++) {
            if (pos >= final_pos) {
                return true;
            }
            pos = max(pos, i + nums[i]);
        }
        return false;
    }
};