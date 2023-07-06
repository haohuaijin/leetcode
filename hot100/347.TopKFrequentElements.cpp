class Solution {
public:
    struct Element {
        int label;
        int count;
        Element(int l, int c) : label(l), count(c) {}
        bool operator<(const Element& other) const {
            return count > other.count;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        for(int i = 0; i < nums.size(); ++i){
            map[nums[i]] += 1;
        } 
        priority_queue<Element> pq;
        int count = 0;
        for(auto it : map){
            if(count < k){
                pq.push(Element{it.first, it.second});
                count++;
            } else {
                if(it.second > pq.top().count){
                    pq.pop();
                    pq.push(Element{it.first, it.second});
                }
            }
        }
        vector<int> res;
        while(!pq.empty()){
            res.push_back(pq.top().label);
            pq.pop();
        }
        return res;
    }
};
