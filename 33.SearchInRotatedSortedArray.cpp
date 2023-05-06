class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while(left <= right){
            int mid = (left + right) / 2;
            if(nums[mid] == target)
                return mid;

            // 判断mid在整个旋转数组左边还是右边 
            if(nums[left] <= nums[mid]){
                // 判断target在mid的左边还是右边
                if(target >= nums[left] && target < nums[mid]){
                    //先判断，能不能去有序部分遍历(好判断)
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else {
                if(target <= nums[right] && target > nums[mid]){
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        return -1;
    }
};
