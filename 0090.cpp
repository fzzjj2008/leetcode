class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        this->nums = nums;
        subsets(0);
        return output;
    }

    void subsets(int start) {
        output.push_back(line);
        for (int i = start; i < nums.size(); i++) {
            if (i > start && nums[i] == nums[i-1]) {
                start++;
                continue;
            }
            line.push_back(nums[i]);
            subsets(i + 1);
            line.pop_back();
        }
    }
private:
    vector<int> nums;
    vector<vector<int>> output;
    vector<int> line;
};