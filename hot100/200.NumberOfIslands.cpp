class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        int m = grid.size();
        int n = grid[0].size();

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1'){
                    count++;
                    dfs(grid, m, n, i, j);
                }
            }
        }
        return count;
    }
    void dfs(vector<vector<char>>& grid, int m, int n, int i, int j){
       grid[i][j] = 0; 
       if(i-1 >= 0 && grid[i-1][j] == '1'){
           dfs(grid, m, n, i-1, j);
       }
       if(i+1 < m && grid[i+1][j] == '1'){
           dfs(grid, m, n, i+1, j);
       }
       if(j-1 >= 0 && grid[i][j-1] == '1'){
           dfs(grid, m, n, i, j-1);
       }
       if(j+1 < n && grid[i][j+1] == '1'){
           dfs(grid, m, n, i, j+1);
       }
    }
};
