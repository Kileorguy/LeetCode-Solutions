class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int size = nums.size();
        unordered_map<int, bool> um;

        for(int i = 0; i<size ; i++){
            if(um.count(nums[i])){
                return true;
            }
            um[nums[i]] = true;
        }
        return false;
    }
};