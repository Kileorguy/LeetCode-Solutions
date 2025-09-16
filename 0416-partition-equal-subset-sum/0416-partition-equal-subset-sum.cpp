class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int total = 0;
        for(const int num: nums) total+=num;
        if(total % 2 != 0) return false;

        int target = total/2;

        vector<bool> dp(target+1, false);
        dp[0] = true;

        for(const int num: nums){
            for(int i=target; i>=num;i--){
                dp[i] = dp[i - num] || dp[i];
                if(dp[target]) return true;
            }
        }
        return false;
    }
};