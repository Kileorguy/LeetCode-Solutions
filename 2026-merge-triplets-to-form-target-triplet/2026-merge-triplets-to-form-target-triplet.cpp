class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<int> curr;
        curr.push_back(0);
        curr.push_back(0);
        curr.push_back(0);

        for(vector<int> &t: triplets){
            // cout << curr[0] << " " << curr[1] << " " << curr[2] << endl;

            if(t[0] <= target[0] && t[1] <= target[1] && t[2] <= target[2]){
                curr[0] = max(curr[0], t[0]);
                curr[1] = max(curr[1], t[1]);
                curr[2] = max(curr[2], t[2]);
            }

            if(curr[0] == target[0] 
                && curr[1] == target[1] 
                && curr[2] == target[2]) return true;
        }
        return false;
    }
};