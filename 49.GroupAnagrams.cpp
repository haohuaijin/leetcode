class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> record;
        for(auto str : strs){
            string t = string(str);
            sort(str.begin(), str.end());
            record[str].push_back(t);
        }
        for (auto it = record.begin(); it != record.end(); ++it) {
            res.emplace_back(it->second);
        }
        return res;
    }
};
