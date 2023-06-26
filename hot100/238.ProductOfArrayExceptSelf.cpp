class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size(), 1);
        // 计算i左边的乘积
        int product = nums[0];
        for(int i = 1; i < nums.size(); i++){
            res[i] = product;
            product *= nums[i];
        }
        // 计算i右边的乘积
        product = nums[nums.size()-1];
        for(int i = nums.size() - 2; i >= 0; i--){
            res[i] *= product;
            product *= nums[i];
        }
        return res;
    }
};
