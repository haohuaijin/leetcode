class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int l = 0;
        int r = nums.size() - 1;
        k -= 1;
        while (true){
            int pivot = helper(nums, l, r);
            if(pivot == k){
                return nums[pivot];
            } else if (pivot < k){
                l = pivot + 1;
            } else {
                r = pivot - 1;
            }   
        }
        return -1;
    }

    int helper(vector<int> & nums, int l, int r){
        int pivot = nums[l];
        int start = l;
        while (l < r){
            while (l < r && nums[r] <= pivot)
                r--;
            while (l < r && nums[l] >= pivot)
                l++;
            if(l < r)
                swap(nums[l], nums[r]);
        }
        swap(nums[start], nums[l]);
        return l;
    }
};
