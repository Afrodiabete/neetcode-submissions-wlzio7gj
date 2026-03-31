class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int left_max = 0, right_max = 0;
        int result = 0;

        while (left < right) {
            // 哪邊的高度矮，就從哪邊開始計算，因為水位高度是被矮的那邊限制的
            if (height[left] < height[right]) {
                if (height[left] >= left_max) {
                    left_max = height[left]; // 更新左側最大值
                } else {
                    result += left_max - height[left]; // 累加水量
                }
                left++;
            } else {
                if (height[right] >= right_max) {
                    right_max = height[right]; // 更新右側最大值
                } else {
                    result += right_max - height[right]; // 累加水量
                }
                right--;
            }
        }
        return result;
    }
};