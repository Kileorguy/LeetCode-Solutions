class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int start = 0,wordLen = 1;

        vector<vector<bool>> dp(n, vector<bool>(n));

        for(int i=0;i<n;i++){
            dp[i][i] = true;
            if(i!=n-1 && s[i] == s[i+1]){
                dp[i][i+1] = true;
                start= i;
                wordLen = 2;
            }
        }

        for(int len=3;len<=n;len++){
            for(int i=0;i<=n-len;i++){
                int j = i + len - 1;

                if(s[i] == s[j] && dp[i+1][j-1] == true){
                    dp[i][j] = true;
                    if(wordLen < len){
                        start = i;
                        wordLen = len; 
                    }
                }
            }
        }
        return s.substr(start, wordLen);
    }
};