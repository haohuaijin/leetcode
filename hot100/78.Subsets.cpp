class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;
        for(int i = 0; i <= nums.size(); i++){
            helper(res, nums, cur, i, 0);
        }
        return res;
    }
    void helper(vector<vector<int>>& res, vector<int>& nums, vector<int>& cur, int n, int index){
        if(cur.size() == n){
            res.push_back(cur);
        } else {
            for(int i = index; i < nums.size(); i++){
                cur.push_back(nums[i]);
                helper(res, nums, cur, n, i+1);
                cur.pop_back();
            }
        }
    }
};
