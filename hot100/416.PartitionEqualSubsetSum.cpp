class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // 没法分割成两部分
        if (nums.size() == 1) {
            return false;
        }
        int sum = accumulate(nums.begin(), nums.end(), 0); // 计算数组和
        int maxNum = *max_element(nums.begin(), nums.end()); // 计算数组最大元素
        // 数组和是奇数，没法分割成相等的两部分
        if (sum & 1) {
            return false;
        }
        int target = sum / 2;
        // 最大元素大于数组和的一半
        if (maxNum > target) {
            return false;
        }

        // dp[i][j]: 记录在nums数组的[0,i]中数组和可不可以等于j
        vector<vector<int>> dp(nums.size(), vector<int>(target + 1, 0));
        for (int i = 0; i < nums.size(); i++) {
            dp[i][0] = true;
        }

        dp[0][nums[0]] = true;
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 1; j <= target; j++) {
                if (j >= nums[i]) {
                    dp[i][j] = dp[i - 1][j] | dp[i - 1][j - nums[i]];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[nums.size() - 1][target];
    }
};
