class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int minVal = prices[0];
        int len = prices.size();
        for(int i = 1; i < len ; i++){
            profit = max(prices[i] - minVal, profit);
            minVal = min(minVal, prices[i]);
        }
        return profit;
    }
};