class Solution {
public:

    void recursive(vector<vector<int>> &ans, vector<int> &subs, vector<int> &nums, int depth, int idx, int prev){
        if(idx == depth){
            ans.push_back(subs);
            return;
        }

        

        subs.push_back(nums[idx]);
        recursive(ans,subs,nums,depth,idx+1, nums[idx]);
        
        subs.pop_back();

        while(idx+1 < depth && nums[idx] == nums[idx+1]) idx++;

        recursive(ans,subs,nums,depth,idx+1, nums[idx]);

    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subs;

        sort(nums.begin(), nums.end());
        
        recursive(ans,subs, nums, nums.size(),0, -1);

        return ans;
    }
};