class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, 0);
        sort(coins.begin(), coins.end(), greater<int>()); 
        return helper(coins, amount, dp);
    }

    int helper(vector<int>& coins, int amount, vector<int>& dp){
        if(amount == 0){
            return 0;
        }
        if(dp[amount] != 0){
            return dp[amount];
        }
        int count = INT_MAX;
        for(int i = 0; i < coins.size(); i++){
            if(amount >= coins[i]){
                int res = helper(coins, amount - coins[i], dp);
                if(res != -1){
                    count = min(count, res + 1);
                }
            }
        }
        dp[amount] = count == INT_MAX ? -1 : count;
        return dp[amount];
    }
};
