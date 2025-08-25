class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n==0) return 0;
        if(n==1) return nums[0];

        vector<int> dp(n);
        vector<int> dp1(n);

        dp[n-1] = 0;
        dp[n-2] = nums[n-2];

        for(int i=n-3;i>=0;i--){
            dp[i] = max(dp[i+1], nums[i] + dp[i+2]);
        }

        dp1[0] = 0;
        dp1[1] = nums[1];

        for(int i=2;i<n;i++){
            dp1[i] = max(dp1[i-1], dp1[i-2] + nums[i]);
        }


        return max(dp[0], dp1[n-1]);
    }
};