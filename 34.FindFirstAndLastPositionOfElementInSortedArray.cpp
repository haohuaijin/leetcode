class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        return {search(nums, target, true), search(nums, target, false)};
    }
    int search(vector<int>& nums, int target, int flag){
        int left = 0, right = nums.size()-1;
        int ans = -1;
        while(left <= right){
            int mid = (left + right) / 2;
            if(nums[mid] < target){
                left = mid + 1;
            } else if(nums[mid] > target){
                right = mid - 1;
            } else {
                if(flag)
                    right = mid - 1;
                else 
                    left = mid + 1;
                ans = mid;
            }
        } 
        return ans;
    }
};
