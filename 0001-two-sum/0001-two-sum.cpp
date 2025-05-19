class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int len = nums.size();
        unordered_map<int,int> um;
        int val;
        for(int i=0;i<len;i++){
            val = target - nums[i];
            if(um.find(val) != um.end()){
                return {um[val], i};
            }
            um[nums[i]] = i;
        } 
        return {};
    }
};