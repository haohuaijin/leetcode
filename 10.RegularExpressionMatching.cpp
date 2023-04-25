class Solution {
public:
    // 题目中'*'表示[字符+*]是一个整体，也就是说'*'前面的字符，
    // 可以匹配0-n次
    // 例如s = "b", p = "ba*" -> Output = true
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();

        auto matches = [&](int i, int j) {
            if (i == 0) {
                return false;
            }
            if (p[j - 1] == '.') {
                return true;
            }
            return s[i - 1] == p[j - 1];
        };

        vector<vector<int>> f(m + 1, vector<int>(n + 1));
        f[0][0] = true;
        for (int i = 0; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j - 1] == '*') {
                    f[i][j] |= f[i][j - 2]; // f[i][j-2]表示不适用'*'匹配任何字符
                    // 这里的match匹配的是'*'代表的字符，和s中i位置的字符(i=1,2,3,4...)
                    if (matches(i, j - 1)) {
                        f[i][j] |= f[i - 1][j];
                    }
                }
                else {
                    if (matches(i, j)) {
                        f[i][j] |= f[i - 1][j - 1];
                    }
                }
            }
        }
        return f[m][n];
    }
};
