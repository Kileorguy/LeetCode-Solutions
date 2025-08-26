class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        vector<int> dp(amount+1, INT_MAX-1);
        dp[0] = 0;
        for(const int coin : coins){
            for(int j = coin; j <= amount ;j++){
                dp[j] = min(dp[j - coin]+1, dp[j]);
            }
        }

        return dp[amount] == INT_MAX-1 ? -1 : dp[amount];

    }
};