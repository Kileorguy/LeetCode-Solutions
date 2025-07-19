class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        auto it = intervals.begin();
        vector<int> &prev = *it; ++it;
        ans.push_back(prev);
        for(it; it!=intervals.end(); ++it){
            vector<int> &curr = *it;
            if(ans.back()[1] >= curr[0]){
                ans.back()[1] = max(ans.back()[1], curr[1]);
            }else{
                ans.push_back(curr);
            }
        }
        return ans;
    }
};