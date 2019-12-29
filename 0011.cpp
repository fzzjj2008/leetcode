class Solution {
public:
    int maxArea(vector<int>& height) {
        int max = 0;
        int left = 0;
        int right = height.size() - 1;

        while (left < right) {
            int cur = calc_area(height, left, right);
            if (cur > max) {
                max = cur;
            }
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        return max;
    }

    int calc_area(vector<int>& height, int left, int right) {
        int min_height = (height[left] < height[right] ? height[left] : height[right]);
        return (min_height * (right - left));
    }
};