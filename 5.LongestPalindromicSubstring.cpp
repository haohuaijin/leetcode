class Solution {
public:
    // 中心扩散法
    string longestPalindrome(string s) {
        string res = "";
        for(int i = 0; i < s.size(); i++){
            string odd = PalindromicSubstring(s, i-1, i+1); 
            string even = PalindromicSubstring(s, i-1, i);
            if(odd.size() > res.size()){
                res = odd;
            } 
            if(even.size() > res.size()){
                res = even;
            }
        }
        return res;
    }

    string PalindromicSubstring(string& s, int i, int j){
        for(; i >= 0 && j < s.size(); i--, j++){
            if(s[i] != s[j]){
                return s.substr(i+1, j-i-1);
            }
        }
        // 这里可以返回子串的位置，速度更快，内存更小
        return s.substr(i+1, j-i-1);
    }
};
