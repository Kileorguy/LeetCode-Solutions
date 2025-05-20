class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, vector<string>> um;
        int len = strs.size();
        string key;
        for (int i = 0; i < len; i++){
            array<int,26> map = {};
            key = "";

            for(char x: strs[i]){
                map[x-'a']+=1;
            }
            for(int j=0;j<26;j++){
                key += to_string(map[j]) + '#';
            }

            um[key].push_back(strs[i]);
        }
        vector<vector<string>> ans;
        vector<string> test;
        for(auto pair: um){
            test = pair.second;
            ans.push_back(test);
        }
        return ans;
    }
};