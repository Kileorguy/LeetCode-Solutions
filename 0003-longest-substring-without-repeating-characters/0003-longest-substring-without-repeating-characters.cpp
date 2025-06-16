class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> um;
        int len = 0, left =0 ;
        int ans = 0;
        int size = s.length();
        for(int i=0;i<size;i++){
            char x = s[i];
            while(um.find(x) != um.end()){
                // cout << "Reset" << endl;
                ans = max(ans,len);
                len -= 1;
                um.erase(s[left]);
                left+=1;
            }
            // cout << x << endl;
            um[x] += 1;
            len+=1;
        }
        return max(len,ans);
    }
};