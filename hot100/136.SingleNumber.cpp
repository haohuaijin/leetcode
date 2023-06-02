// class Solution {
// public:
//     int singleNumber(vector<int>& nums) {
//         unordered_map<int,int> map;
//         for(int i = 0; i < nums.size(); i++){
//             map[nums[i]] += 1;
//         }
//         for(auto& it : map){
//             if(it.second == 1){
//                 return it.first;
//             }
//         }
//         return -1;
//     }
// };

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < nums.size(); i++){
            res ^= nums[i];
        } 
        return res;
    }
};
