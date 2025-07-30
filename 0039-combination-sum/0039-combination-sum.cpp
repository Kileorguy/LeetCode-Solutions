class Solution {
public:

    void subset(vector<vector<int>> &ans, vector<int> &sub, vector<int> &candidates, int target, int sum, int idx){
        if(sum == target){
            ans.push_back(sub);
            return;
        }

        for(int i = idx;i<candidates.size();i++){
            if(sum+candidates[i] > target) break;
            sub.push_back(candidates[i]);
            sum += candidates[i];
            subset(ans,sub, candidates, target,sum,i);
            sub.pop_back();
            sum -= candidates[i];
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> sub;

        subset(ans,sub, candidates, target,0,0);


        return ans;
    }
};