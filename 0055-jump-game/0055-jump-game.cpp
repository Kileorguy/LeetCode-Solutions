class Solution {
public:
    bool canJump(vector<int>& nums) {
        int size = nums.size();
        int i = 0;
        int maxVal = INT_MIN;
        while(i < size && nums[i] != 0){
            // cout << "while" << endl;
            // cout << i << endl;
            if(i + nums[i]>=size-1) return true;
            maxVal = INT_MIN;
            int iterCount = i+nums[i];
            for(int j=i+1; j<=iterCount && j < size; j++){
                // maxVal = max(maxVal, nums[j]);
                // i = j;
                if(maxVal <= nums[j] + j){
                    maxVal = nums[j] + j;
                    i = j;
                }
            }
            // cout << i << endl;
            // cout << "end while" << endl;

        }
        // cout << "outside" << endl;
        // cout << i << endl;

        if(i >= size-1) return true;
        else if(nums[i] == 0) return false;
        return true;
        
    }
    

};