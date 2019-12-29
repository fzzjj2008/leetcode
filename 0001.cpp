class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashmap;
        int len = nums.size();
        for (int i = 0; i < len; i++) {
            if (hashmap.count(target - nums[i]) > 0) {
                return {hashmap[target - nums[i]], i};
            } else {
                hashmap[nums[i]] = i;
            }
        }
        return {-1, -1};
    }
};