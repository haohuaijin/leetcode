class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();  
        int res = 0;
        // dp[i][j]表示以(i,j)为右下角的正方形的最大边长
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 || j == 0){
                    dp[i][j] = matrix[i][j] - '0';
                } else if(matrix[i][j] == '1') {
                    dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1])) + 1;
                } 
                cout << "i: " << i << ", j: " << j << ", dp: " << dp[i][j] << endl;
                res = max(res, dp[i][j]);
            }
        }
        return res * res;
    }
};
