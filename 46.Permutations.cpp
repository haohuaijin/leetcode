class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;
        bool visit[8];
        fill(visit, visit+8, false);
        helper(res, nums, cur, visit, 0, nums.size());
        return res;
    }
    void helper(vector<vector<int>>&res, vector<int>& nums, vector<int>& cur, bool* visit, int count, int len){
        if(count == len){
            res.push_back(cur);
        } else {
            for(int i = 0; i < nums.size(); i++){
                if(!visit[i]){
                    visit[i] = true;
                    cur.push_back(nums[i]);
                    helper(res, nums, cur, visit, count+1, len);
                    cur.pop_back();
                    visit[i] = false;
                }
            }
        }
    }
};
