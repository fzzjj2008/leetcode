class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        this->n = n;
        this->k = k;
        backtrack(1, 0);
        return output;
    }
    void backtrack(int start, int layer) {
        if (layer == k) {
            output.push_back(line);
            return;
        }
        for (int i = start; i <= n; i++) {
            line.push_back(i);
            backtrack(start + 1, layer + 1);
            line.pop_back();
            start++;
        }
    }
private:
    int n;
    int k;
    vector<vector<int>> output;
    vector<int> line;
};