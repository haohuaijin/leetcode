class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> left(m, vector<int>(n, 0));
        int res = 0;

        // 初始化left,left记录matrix[i][j]左边连续1的数量(包含matrix[i][j])
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == '1'){
                    left[i][j] = (j == 0 ? 0 : left[i][j-1]) + 1;
                }
            }
        }

        for(int j = 0; j < n; j++){
            // up 和 dwon 分别记录j列在每一行可以向上和向下可以扩展到的位置
            vector<int> up(m, 0), down(m, 0);

            stack<int> st;
            for(int i = 0; i < m; i++){
                while(!st.empty() && left[st.top()][j] >= left[i][j]){
                    st.pop();
                }
                up[i] = st.empty() ? -1 : st.top();
                st.push(i);
            }

            st = stack<int>();
            for(int i = m-1; i >= 0; i--){
                while(!st.empty() && left[st.top()][j] >= left[i][j]){
                    st.pop();
                }
                down[i] = st.empty() ? m : st.top();
                st.push(i);
            }

            for(int i = 0; i < m; i++){
                int heiget = down[i] - up[i] - 1;
                res = max(res, heiget * left[i][j]);
            }
        }

        return res;
    }
};
