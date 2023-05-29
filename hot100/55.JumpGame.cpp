class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_index = 0; //记录当前能够跳到的最远位置
        for(int i = 0; i < nums.size(); i++){
            if(i > max_index)
                return false;
            if(max_index >= nums.size() - 1)
                return true;
            max_index = max(max_index, i + nums[i]);
        }
        return true;
    }
};
