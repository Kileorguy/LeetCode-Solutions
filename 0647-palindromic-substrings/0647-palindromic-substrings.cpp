class Solution {
public:
    int countSubstrings(string s) {

        int ans = 0;

        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n));

        for(int i=0;i<n;i++){
            dp[i][i] = true;
            ans++;
            if(i != n-1 && s[i+1] == s[i]){
                dp[i][i+1] = true;
                ans++;
            }
        }

        for(int len=3;len<=n;len++){
            for(int i=0;i<=n-len;i++){
                int j = i + len - 1;
                
                if(s[i] == s[j] && dp[i+1][j-1]){
                    dp[i][j] = true;
                    ans++;
                }

            }
        }

        return ans;

        
    }
};