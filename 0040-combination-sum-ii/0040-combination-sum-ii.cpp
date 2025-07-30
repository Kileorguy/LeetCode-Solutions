class Solution {
public:

    void recur(vector<vector<int>> &ans, vector<int> &sub, vector<int> &candidates, int target, int idx, int sum){

        if(sum == target) ans.push_back(sub);
        int prev = -1;
        for(; idx < candidates.size(); idx++){
            if(sum+candidates[idx] > target) break;
            if(idx > 0 && candidates[idx] == prev) continue;
            sub.push_back(candidates[idx]);
            sum += candidates[idx];
            recur(ans, sub, candidates, target, idx+1, sum);
            sub.pop_back();
            sum -= candidates[idx];
            prev = candidates[idx];
        }

    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> sub;

        recur(ans, sub, candidates, target, 0, 0);

        return ans;
    }
};