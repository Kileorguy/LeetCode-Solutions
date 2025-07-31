
class Solution {
public:

    void recursive(vector<vector<int>> &ans, vector<int> &nums, vector<int> &subs, int size){

        if(subs.size() == size){
            ans.push_back(subs);
        }

        for(int i=0;i<nums.size();i++){
            int temp = nums.back();
            nums.pop_back();
            subs.push_back(temp);
            recursive(ans, nums, subs,size);

            nums.insert(nums.begin() + 0, temp);
            subs.pop_back();
        }

        

    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subs;

        recursive(ans, nums, subs, nums.size());
        

        return ans;
    }
};