class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;
        int left = 0, right = height.size() - 1;
        int left_max = 0, right_max = 0;
        while (left < right) {
            left_max = max(left_max, height[left]);
            right_max = max(right_max, height[right]);
            if (left_max < right_max){
                // height[left]算在了left_max里面，所以left_max-height[left] >= 0
                res += left_max - height[left];
                ++left;
            } else {
                res += right_max - height[right];
                --right;
            }
        }
        return res;
    }
};
