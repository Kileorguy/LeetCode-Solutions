class Solution {
public:

    int binary(vector<int> &nums, int left, int right){
        if(left>=right) return nums[left];
        
        int middle = left + (right-left)/2;

        if(nums[middle] > nums[right]){
            return binary(nums, middle+1, right);
        }else{
            return binary(nums, left, middle);
        }
    }

    int findMin(vector<int>& nums) {
        return binary(nums, 0, nums.size()-1);
    }
};