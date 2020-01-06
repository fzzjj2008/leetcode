class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if (heights.size() == 0) {
            return 0;
        }
        int start = 0;
        int max_area = 0;
        bool flag = false;
        //分成多个堆
        for (int i = 1; i < heights.size() - 1; i++) {
            if (heights[i-1] > heights[i]) {
                flag = true;
            }
            if (flag == true && heights[i] < heights[i+1]) {
                flag = false;
                max_area = max(max_area, calc_area(heights, start, i));
                start = i;
            }
        }
        max_area = max(max_area, calc_area(heights, start, heights.size() - 1));

        return max_area;
    }

    //计算每个堆的最大面积
    //area = max(area, [right-left+1]*min(heights[left],heights[right]))
    int calc_area(vector<int>& heights, int start, int end) {
        int max_index = 0;
        int max_height = heights[start];
        for (int i = start + 1; i <= end; i++) {
            if (heights[i] > max_height) {
                max_height = heights[i];
                max_index = i;
            }
        }
        int max_area = max_height;
        int min_height = max_height;
        int left = max_index;
        int right = max_index;
        while (1) {
            if (left-1 < 0 && right+1 >= heights.size()) {
                break;
            } else if (left-1 < 0) {
                min_height = min(min_height, heights[++right]);
            } else if (right+1 >= heights.size()) {
                min_height = min(min_height, heights[--left]);
            } else {                
                if (heights[left-1] >= heights[right+1]) {
                    min_height = min(min_height, heights[--left]);
                } else {
                    min_height = min(min_height, heights[++right]);
                }
            }
            int area = (right-left+1) * min_height;
            if (area > max_area) {
                max_area = area;
            }
        }

        return max_area;
    }
};