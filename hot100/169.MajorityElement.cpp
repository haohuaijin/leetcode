class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res = nums[0];
        int count = 1;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == res){
                count++;
                continue;
            } 
            count--;
            if(count == -1){
                res = nums[i];
                count = 1;
            }            
        }
        return res;
    }
};
