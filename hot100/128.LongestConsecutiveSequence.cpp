class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for(int i = 0; i < nums.size(); i++){
            s.insert(nums[i]);
        }

        int max = 0;
        for(int i = 0; i < nums.size(); i++){
            if(s.count(nums[i]-1) == 0){
                int count = 1;
                int num = nums[i] + 1;
                while(s.count(num) != 0){
                    num++;
                    count++;
                }
                max = std::max(max, count);
            }
        }
        return max;
    }
};
