class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> com; 
        helper(res, candidates, com, target, 0);
        return res;
    }
    void helper(vector<vector<int>>& res, vector<int>& candidates, vector<int>& com, int target, int index){
        if(target == 0){
            res.push_back(com);
        } else {
            for(int i = index; i < candidates.size(); i++){
                // 这里可以使用target < candidates[i]进行剪枝，
                // 不过如何要使用这种方法剪枝的话，就需要对candidates进行排序
                if(target >= candidates[i]){
                    com.push_back(candidates[i]);
                    helper(res, candidates, com, target-candidates[i], i);
                    com.pop_back();
                }
            }
        }
    }
};
