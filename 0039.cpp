class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if (candidates.size() == 0) {
            return result;
        }
        this->candidates = candidates;
        combinationSum(target, 0);
        return result;       
    }
    
    void combinationSum(int target, int start) {
        if (target == 0) {
            result.push_back(list);
        } else if (target > 0) {
            for (int i = start; i < candidates.size(); i++) {
                list.push_back(candidates[i]);
                combinationSum(target - candidates[i], i);
                list.pop_back();
            }
        }
    }
private:
    vector<int> candidates;
    vector<vector<int>> result;
    vector<int> list;
};