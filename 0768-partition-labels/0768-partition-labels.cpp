class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> endMap;
        int len = s.length();
        char c;
        for(int i=0;i<len;i++){
            c = s[i];
            endMap[c] = i;
        }
        vector<int> ans;
        int start = 0, end = 0;
        for(int i=0;i<len;i++){
            c = s[i];
            end = max(end, endMap[c]);
            if(end == i){
                ans.push_back(end-start+1);
                start = i+1;
            }
        }
        return ans;
    }
};