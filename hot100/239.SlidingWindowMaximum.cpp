class Solution {
public:
    // Monotonic queue
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q; // record index
        vector<int> res;
        for(int i = 0; i < k; i++){
            while(!q.empty() && nums[i] >= nums[q.back()]){
                q.pop_back();
            }
            q.push_back(i);
        }
        res.push_back(nums[q.front()]);
        for(int i = k; i < nums.size(); i++){
            while(!q.empty() && nums[i] >= nums[q.back()]){
                q.pop_back();
            }
            q.push_back(i);
            while(q.front() <= i - k){
                q.pop_front();
            }
            res.push_back(nums[q.front()]);
        }
        return res;
    }
};
