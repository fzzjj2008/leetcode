class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> output;
        int new_start = newInterval[0];
        int new_end = newInterval[1];
        
        for (int i = 0; i < intervals.size(); i++) {
            int start = intervals[i][0];
            int end = intervals[i][1];
            if (end < new_start) {
                output.push_back(intervals[i]);
            } else if (start > new_end) {
                continue;
            }
            if (end >= new_start && start <= new_start) {
                new_start = start;
            }
            if (start <= new_end && end >= new_end) {
                new_end = end;
            }
        }
        output.push_back({new_start, new_end});

        for (int i = 0; i < intervals.size(); i++) {
            if (intervals[i][0] > new_end) {
                output.push_back(intervals[i]);
            }
        }
        return output;
    }
};