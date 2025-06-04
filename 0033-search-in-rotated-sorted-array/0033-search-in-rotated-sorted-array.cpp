class Solution {
public:

    int binary(vector<int> &nums, int left, int right, int target){
        // cout << left << " " + to_string(right) << endl;
        if(right < left) return -1;


        int middle = left + (right-left)/2;

        if(nums[middle] == target) return middle;
        
        if(nums[middle] >= nums[left]){
            if(target < nums[middle] && target >= nums[left]) 
                return binary(nums, left, middle-1, target);
            else 
                return binary(nums, middle+1, right, target);
        }else{
            if(target > nums[middle] && target <= nums[right] ) return binary(nums, middle+1, right, target);
            else return binary(nums, left, middle-1,target);
        }
    }

    int search(vector<int>& nums, int target) {
        return binary(nums, 0, nums.size()-1, target);
    }
};