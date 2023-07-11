class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        unordered_map<char, int> p1;
        unordered_map<char, int> p2;
        
        for(int i = 0; i < p.size(); i++){
            char c = p[i];
            if(p1.count(c) == 0){
                p1[c] = 1;
            } else {
                p1[c] += 1;
            }
        }

        int index = 0;
        for(int i = 0; i < s.size(); i++){
            char c = s[i];
            if(p1.count(c) == 0){
                p2.clear();
                index = i + 1;
            } else {
                if(p2[c] != p1[c]){
                    p2[c] += 1;
                } else {
                    int j = index;
                    for(; s[j] != c; j++){
                        p2[s[j]] -= 1;
                    }
                    index = j + 1;
                }
            }
            if(i - index + 1 == p.size()){
                res.push_back(index);
            }
        }
        return res;
    }
};
