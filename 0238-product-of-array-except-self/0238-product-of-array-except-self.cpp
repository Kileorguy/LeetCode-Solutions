class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int curr = 1;
        int len = nums.size();
        vector<int> ans(len,1); 
        for(int i=1; i<len; i++){
            curr = curr * nums[i-1];
            ans[i] = ans[i] * curr;
        }
        
        
        curr = 1;
        for(int i=len-2; i>=0 ; i--){
            curr = curr * nums[i+1];
            ans[i] = ans[i] * curr;
        }

        return ans;

    }
};