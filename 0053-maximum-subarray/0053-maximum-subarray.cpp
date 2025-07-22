class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxVal = nums[0];
        int currSum = nums[0];
        int size = nums.size();

        for(int i=1; i<size; i++){
            currSum = max(nums[i], currSum+nums[i]);
            maxVal = max(currSum, maxVal);
        }
        return maxVal;
    }
};