class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> table;
        for(int i = 0; i < nums.size(); i++){
            if(table.count(target - nums[i]) > 0) {
                return {table[target-nums[i]], i};
            }
            table[nums[i]] = i;
        }     
        return {};
    }
};
