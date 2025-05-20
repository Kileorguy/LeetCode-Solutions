class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;
        unordered_map<int,int> um;
        for(int x: nums){
            if(um.count(x)==0){
                um[x] = 1;
            }else{
                um[x] += 1;
            }
        }

        for(auto pair: um){
            pq.push({pair.second, pair.first});
        }
        vector<int> ans;
        for(int i=0;i<k;i++){
            pair<int,int> a; 
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
        
    }
};