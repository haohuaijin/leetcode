class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int res = 0;
        helper(nums, target, 0, res);
        return res;
    }
    void helper(vector<int>& nums, int target, int index, int& res){
        if(index == nums.size()){
            if(target == 0){
                res += 1;
            } 
            return;
        }

        int num = nums[index]; 
        helper(nums, target - num, index+1, res);
        helper(nums, target + num, index+1, res);
    }
};
