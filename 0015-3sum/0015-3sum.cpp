class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        
        int len = nums.size();
        int left=0 ,right = len - 1;
        int sum=0;
        for(int i=0;i<len;i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;
            left = i+1;
            right = len - 1;
            while(left < right){
                sum = nums[i] + nums[left] + nums[right];
                if(sum < 0) left++;
                else if(sum> 0) right--;
                else{
                    ans.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    while(nums[left] == nums[left-1] && left < right){
                        left++;
                    }

                }
            }
        }
        return ans;

    }
};