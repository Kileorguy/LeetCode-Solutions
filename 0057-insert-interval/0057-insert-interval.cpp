class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        
        vector<pair<int,int>> indexed;
        int size = intervals.size();

        indexed.push_back({newInterval[0],-1});
        indexed.push_back({newInterval[1],-1});

        for(int i=0;i<size;i++){
            indexed.push_back({intervals[i][0], i});
            indexed.push_back({intervals[i][1], i});
        }

        sort(indexed.begin(), indexed.end(), [](auto& a, auto& b) {
            return a.first < b.first;
        });

        unordered_map<int,int> indexQ;
        vector<int> dq;
        
        for(pair<int,int> &val: indexed){
            indexQ[val.second] += 1;
            dq.push_back(val.first);
            bool check = true;
            for(auto it = indexQ.begin(); it != indexQ.end(); ++it){
                if(it->second != 2){
                    check = false;
                    break;
                }
            }

            if(check){
                indexQ.clear();
                int size = ans.size();
                if(size > 0 && ans[size-1][1] == dq.front()){
                    ans[size-1][1] = dq.back();
                }else{
                    ans.push_back({dq.front(), dq.back()});
                }
                dq.clear();
            }
            
        }

        return ans;
    }
};