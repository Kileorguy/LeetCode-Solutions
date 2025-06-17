class Solution {
public:
    int characterReplacement(string s, int k) {

        unordered_map<char,int> um;

        int left = 0;
        int len = s.length();
        int ans = 0;
        int maxCount = 0;

        for(int right = 0; right<len ;right++){

            um[s[right]] +=1;
            maxCount = max(maxCount, um[s[right]]);
            
            while(left < right && right - left + 1 - maxCount > k){
                um[s[left]]--;
                left++;
            }
            
            ans = max(right-left+1, ans);
        }
        return ans;
    }
};