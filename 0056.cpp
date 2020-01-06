class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> output;
        sort(intervals.begin(), intervals.end());
        for (int i = 0; i < intervals.size(); i++) {
            if (output.empty() || output.back()[1] < intervals[i][0]) {
                output.push_back(intervals[i]);
            } else {
                output.back()[1] = max(output.back()[1], intervals[i][1]);
            }
        }
        return output;
    }
};