class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> res;
        res.push_back(intervals[0]);

        for(auto it=intervals.begin(); it != intervals.end(); ++it){
            vector<int> &pair= *it;
            if(res.back()[1] >= pair[0]){
                res.back()[1] = max(pair[1], res.back()[1]);
            }else{
                res.push_back(pair);
            }
        }
        return res;
    }
};