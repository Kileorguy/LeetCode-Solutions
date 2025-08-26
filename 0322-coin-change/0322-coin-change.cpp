class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        coins.insert(coins.begin(), 0);

        vector<vector<pair<int,int>>> dp(n+1, vector<pair<int,int>>(amount+1,{-1,0}));

        for(int j=0;j<=amount;j++){
            dp[0][j].first = 1e9;
            dp[0][j].second = 0;
        }

        for(int i=0;i<=n;i++){ dp[i][0].first = 0; }
        dp[0][0] = {0,0};
        

        for(int w=1;w<=n;w++){
            for(int j=1;j<=amount;j++){
                dp[w][j] = dp[w-1][j];
                if(j >= coins[w]){
                    int candidate = 1 + dp[w][j - coins[w]].first;
                    if(candidate < dp[w][j].first){
                        dp[w][j].first = candidate;
                        dp[w][j].second = dp[w][j-coins[w]].second + coins[w];
                    }
                }
            }
        }
        
        if(dp[n][amount].second == amount){
            return dp[n][amount].first;
        }else{
            return -1;
        }


    }
};