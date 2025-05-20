
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, vector<string>> um;
        int len = strs.size();
        for(string a: strs){
            string copy = a;
            sort(a.begin(), a.end());
            um[a].push_back(copy);
        }
        vector<vector<string>> ans;
        for(auto pair: um){
            ans.push_back(pair.second);
        }
        return ans;
    }
};