class Solution {
public:
    int numDistinct(string s, string t) {
        vector<vector<unsigned long long int>> dp(t.length()+1, vector<unsigned long long int>(s.length()+1,0));

        for(int i=1;i<=s.length();i++){
            // cout << t[0] << " " << s[i-1] << endl;
            if(t[0] == s[i-1]) dp[1][i] = dp[1][i-1] + 1;
            else dp[1][i] = dp[1][i-1];
        }

        for(int i=2;i<=t.length();i++){
            for(int j=1;j<=s.length();j++){
                if(t[i-1] == s[j-1]) dp[i][j] = (dp[i][j-1] + dp[i-1][j-1]);
                else dp[i][j] = dp[i][j-1];
            }
        }

        // for(int i=0;i<=t.length();i++){
        //     for(int j=0;j<=s.length();j++){
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << "" << endl;
        // }
        

        return dp[t.length()][s.length()];
    }
};