class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //找规律, 先水平翻转，然后对角线翻转
        int len = matrix.size();
        for(int i = 0; i < len / 2; i++){
            for(int j = 0; j < len; j++){
                swap(matrix[i][j], matrix[len-i-1][j]);
            }
        }
        for(int i = 1; i < len; i++){
            for(int j = 0; j < i; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};
