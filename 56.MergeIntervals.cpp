class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end());
        int start = intervals[0][0];
        int end = intervals[0][1];
        for(int i = 1; i < intervals.size(); i++){
            vector<int>& interval = intervals[i];
            if(end >= interval[0]){
                end = max(end, interval[1]);
            } else {
                res.push_back({start, end});
                start = interval[0];
                end = interval[1];
            }
        }
        if(start != -1)
            res.push_back({start, end});
        return res;
    }
};
