class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> map;
        int max_len = 0; 
        int start = 0;
        for(int i = 0; i < s.size(); i++){
            if(map.count(s[i]) == 0){
                map[s[i]] = i;
                if(i - start + 1 > max_len)
                    max_len = i - start + 1;
            } else {
                for(int j = start; j < map[s[i]]; j++)
                    map.erase(s[j]);
                start = map[s[i]] + 1;
                map[s[i]] = i;
            }
        }
        return max_len;
    }
};
