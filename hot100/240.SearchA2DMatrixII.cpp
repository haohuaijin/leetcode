class Solution {
public:
    // Z search
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int x = 0;
        int y = n-1;
        while(x < m && y >= 0){
            if(matrix[x][y] == target){
                return true;
            } else if(matrix[x][y] > target){
                y = y - 1;
            } else {
                x = x + 1;
            }
        }
        return false;
    }
};
