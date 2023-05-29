class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for(int first = 0; first < nums.size(); first++){
            // 遍历first的时候，跳过相同的first值
            if(first > 0 && nums[first] == nums[first-1]){
                continue;
            }

            int third = nums.size() - 1;
            for(int second = first+1; second < nums.size(); second++){
                // 遍历second的时候，跳过相同的second值
                if(second > first+1 && nums[second] == nums[second-1]){
                    continue;
                }

                while(second < third && nums[first] + nums[second] + nums[third] > 0){
                    third--;
                }
                
                // first > second > thrid
                // 当second == thrid说明此次遍历需要结束了
                if(second == third){
                    break;
                }

                if(nums[first] + nums[second] + nums[third] == 0){
                    res.push_back({nums[first], nums[second], nums[third]});
                }
            }
        }
        return res;
    }
};
