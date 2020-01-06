class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        this->nums = nums;
        subset_add(0);
        return output;
    }

    void subset_add(int start) {
        output.push_back(line);
        for (int i = start; i < nums.size(); i++) {
            line.push_back(nums[i]);
            subset_add(start + 1);
            line.pop_back();
            start++;
        }
    }
private:
    vector<int> nums;
    vector<vector<int>> output;
    vector<int> line;
};