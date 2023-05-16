// class Solution {
// public:
//     int minPathSum(vector<vector<int>>& grid) {
//         int m = grid.size();
//         int n = grid[0].size();
//         vector<vector<int>> dp(m, vector<int>(n, -1));
//         return helper(grid, dp, m, n, 0, 0);
//     }
//     int helper(vector<vector<int>>& grid, vector<vector<int>>& dp, int m, int n, int x, int y){
//         if (x == m-1 && y == n-1){
//             return grid[m-1][n-1];
//         } else {
//             if(dp[x][y] != -1){
//                 return dp[x][y];
//             }
//             int res;
//             int left = -1, right = -1;
//             if(x != m - 1)
//                 left = helper(grid, dp, m, n, x+1, y);
//             if(y != n-1)
//                 right =  helper(grid, dp, m, n, x, y+1);
//             if(left == -1) res = right;
//             else if(right == -1) res = left;
//             else res = min(left, right);
//             dp[x][y] = res + grid[x][y];
//             return dp[x][y];
//         }
//     }
// };
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = grid[0][0];
        for(int i = 1; i < m; i++)
            dp[i][0] = grid[i][0] + dp[i-1][0];
        for(int i = 1; i < n; i++)
            dp[0][i] = grid[0][i] + dp[0][i-1];
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
            }
        }
        return dp[m-1][n-1];
    }
};
