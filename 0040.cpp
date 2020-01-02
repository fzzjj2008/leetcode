class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        if (candidates.size() == 0) {
            return result;
        }
        sort(candidates.begin(), candidates.end());
        this->candidates = candidates;
        combinationSum2(target, 0);
        return result;
    }

    void combinationSum2(int target, int start) {
        if (target == 0) {
            result.push_back(list);
        } else if (target > 0) {
            for (int i = start; i < candidates.size(); i++) {
                if (i > start && candidates[i] == candidates[i - 1]) {
                    continue;
                }
                list.push_back(candidates[i]);
                combinationSum2(target - candidates[i], i + 1);
                list.pop_back();
            }
        }
    }
private:
    vector<int> candidates;
    vector<vector<int>> result;
    vector<int> list;
};