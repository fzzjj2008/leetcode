//荷兰旗帜问题
//桶排序
class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> bucket = vector<int>(3,0);
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                bucket[0]++;
            } else if (nums[i] == 1) {
                bucket[1]++;
            } else {
                bucket[2]++;
            }
        }
        for (int i = 0; i < bucket[0]; i++) {
            nums[i] = 0;
        }
        for (int i = 0; i < bucket[1]; i++) {
            nums[i + bucket[0]] = 1;
        }
        for (int i = 0; i < bucket[2]; i++) {
            nums[i + bucket[0] + bucket[1]] = 2;
        }
    }
};

//三指针排序（快排改）
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int p0 = 0;
        int p2 = nums.size() - 1;
        int cur = 0;
        while (cur <= p2) {
            if (nums[cur] == 0) {
                swap(nums[cur++], nums[p0++]);
            } else if (nums[cur] == 2) {
                swap(nums[cur], nums[p2--]);
            } else {
                cur++;
            }
        }
    }

    void swap(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }
};