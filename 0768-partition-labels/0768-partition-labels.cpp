class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> startMap;
        unordered_map<char,int> endMap;
        int len = s.length();
        char c;
        for(int i=0;i<len;i++){
            c = s[i];
            if(startMap.count(c) == 0){
                startMap[c] = i;
            }
            endMap[c] = i;
        }
        queue<char> q;
        vector<int> ans;
        int count = 1;
        for(int i=0;i<len;i++){
            c = s[i];
            if(startMap[c] == i) q.push(c);
            if(endMap[c] == i) q.pop();
            if(!q.empty()) count++;
            else{
                ans.push_back(count);
                count = 1;
            }
        }
        return ans;
    }
};