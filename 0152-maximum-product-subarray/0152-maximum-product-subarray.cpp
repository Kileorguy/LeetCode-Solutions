class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int n = nums.size();

        int maxVal, minVal, ans;
        maxVal = minVal = ans = nums[0];

        for(int i=1;i<n;i++){
            if(nums[i] < 0) swap(minVal, maxVal);
            minVal = min(nums[i], nums[i] * minVal);
            maxVal = max(nums[i], nums[i] * maxVal);
            ans = max(maxVal, ans);
        }

        return ans;
        
    }
};