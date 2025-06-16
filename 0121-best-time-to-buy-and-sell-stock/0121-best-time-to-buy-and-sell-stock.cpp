class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int min = 9999999999;
        for(int i:prices){
            if(i < min){
                min = i;
            }
            profit = max(i - min, profit);
        }
        return profit;
    }
};