class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> output(rowIndex+1, 0);
        for (int count = 0; count <= rowIndex; count++) {
            for (int i = rowIndex; i >= 0; i--) {
                if (i == 0) {
                    output[0] = 1;
                } else {
                    output[i] += output[i - 1];
                }
            }
        }
        return output;
    }
};