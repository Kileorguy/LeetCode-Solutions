class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size() + 1;
        vector<int> dp(n);
        dp[n-1] = 0;
        dp[n-2] = nums[n-2];

        for(int i=n-3;i>=0;i--){
            // steal or not steal
            dp[i] = max(nums[i]+dp[i+2], dp[i+1]);
        }
        return dp[0];
    }
};