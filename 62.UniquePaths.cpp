class Solution {
public:
    // 动态规划: 因为有重复的计算
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        return helper(dp, m, n, 0, 0);
    }
    int helper(vector<vector<int>>& dp, int m, int n, int x, int y){
        if(x == m || y == n){
            return 0;
        } else if(x == m-1 && y == n-1) {
            return 1;
        } else {
            if(dp[x][y] != 0){
                return dp[x][y];
            }
            int left = helper(dp, m, n, x+1, y);
            int right = helper(dp, m, n, x, y+1);
            dp[x][y] = left + right;
            return left + right;
        }
    }
};
