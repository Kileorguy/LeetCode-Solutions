class Solution {
public:
    vector<vector<int>> ans;

    void createSubset(vector<int> &nums, vector<vector<int>> &res, vector<int> &subset, int idx){
        if(nums.size() == idx){
            res.push_back(subset);
            return;
        }

        subset.push_back(nums[idx]);
        createSubset(nums,res,subset,idx+1);

        subset.pop_back();
        createSubset(nums,res,subset,idx+1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subset;
        createSubset(nums, ans, subset, 0);

        return ans;
    }
};