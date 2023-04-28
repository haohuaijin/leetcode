class Solution {
public:
    map<char, string> letter = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        string combination;
        helper(res, digits, combination, 0);
        return res;
    }
    void helper(vector<string>& res, string digits, string combination, int index){
        if(digits.empty())
            return;
        char current = digits[0];
        for(int i = 0; i < letter[current].size(); i++){
            combination.push_back(letter[current][i]);
            if(digits.size() == 1){
                res.push_back(combination);
            } else {
                helper(res, digits.substr(1), combination, index+1); 
            }
            combination.pop_back();
        }
    }
};
