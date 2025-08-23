class Solution {
public:
    int rob(vector<int>& nums) {
        int prev1=0, prev2=0, ans;
        for(const int &n: nums){
            ans = max(prev1, prev2+n);
            prev2 = prev1;
            prev1 = ans;
        }

        return ans;
    }
};