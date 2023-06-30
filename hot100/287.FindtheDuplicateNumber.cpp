class Solution {
public:
    // mark
    // int findDuplicate(vector<int>& nums) {
    //     int slow = 0, fast = 0;
    //     do {
    //         slow = nums[slow];
    //         fast = nums[nums[fast]];
    //     } while (slow != fast);
    //     slow = 0;
    //     while (slow != fast) {
    //         slow = nums[slow];
    //         fast = nums[fast];
    //     }
    //     return slow;
    // }
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for(int i = 0; i < nums.size(); i++){
            if(s.count(nums[i]) == 0){
                s.insert(nums[i]);
            } else {
                return nums[i];
            }
        }
        return -1;
    }
};
