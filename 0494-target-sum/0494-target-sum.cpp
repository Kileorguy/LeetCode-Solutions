class Solution {
public:

    void dfs(vector<int> &nums, int &target, int &ans, int &sum, int idx) {
        for (int i=idx; i<nums.size();i++) {
            sum -= nums[i] * 2;
            if (sum == target) ans++;
            dfs(nums, target,ans, sum, i+1);
            sum += nums[i] * 2;
        }

        return;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int ans = 0;
        int sum = 0;
        for (const int n: nums) {
            sum+=n;
        }
        if (target == sum) ans++;

        dfs(nums, target, ans, sum, 0);

        return ans;
    }
};