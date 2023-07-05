class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n+1, 0);
        for(int i = 1; i <= n; i++){
            res[i] = helper(i);
        }
        return res;
    }
    int helper(int num){
        int count = 0;
        while(num != 0){
            num = num & (num - 1);
            count += 1;
        }
        return count;
    }
};
