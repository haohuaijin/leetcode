class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min = prices[0];
        int res = 0;
        for(int i = 1; i < prices.size(); i++){
            if(prices[i] > min){
                res = max(res, prices[i] - min);
            } else {
                min = prices[i];
            }
        }
        return res;
    }
};
