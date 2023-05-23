class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        if (n == 1) {
            return heights[0];
        }
        int res = 0;
        stack<int> st;
        // 哨兵 
        heights.insert(heights.begin(), 0);
        heights.push_back(0);
        st.push(0); //remove the check of !st.empty()
        n += 2;
        for (int i = 1; i < n; ++i) {
            while (heights[st.top()] > heights[i]) {
                int length = heights[st.top()];
                st.pop();
                int width = i - st.top() - 1;
                res = max(res, length * width);
            }
            st.push(i);
        }
        return res;
    }
    // int largestRectangleArea(vector<int>& heights) {
    //     int n = heights.size();
    //     if (n == 1) {
    //         return heights[0];
    //     }
    //     int res = 0;
    //     stack<int> st;
    //     for (int i = 0; i < n; ++i) {
    //         while (!st.empty() && heights[st.top()] > heights[i]) {
    //             int length = heights[st.top()];
    //             st.pop();
    //             int width = i; //栈为空的话，heights[i]一定能够扩展到最左边
    //             if (!st.empty()) {
    //                 width = i - st.top() - 1;
    //             }
    //             res = max(res, length * width);
    //         }
    //         st.push(i);
    //     }
    //     while (!st.empty()) {
    //         int length = heights[st.top()];
    //         st.pop();
    //         int width = n; // 栈为空的话，一定可以扩展到全部的位置
    //         if (!st.empty()) {
    //             width = n - st.top() - 1;
    //         }
    //         res = max(res, length * width);
    //     }
    //     return res;
    // }
};
