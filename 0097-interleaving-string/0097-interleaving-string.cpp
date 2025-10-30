class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.length()+1;
        int m = s2.length()+1;

        // cout << n-1 << " " << m-1 << " " << s3.length() << endl;

        if(n-1 + m-1 != s3.length()) return false;

        vector<vector<int>> dp(n, vector<int>(m,0));
        dp[0][0] = 0;

        for(int i=1;i<n;i++){
            if(s3[i-1] == s1[i-1]) dp[i][0] = dp[i-1][0] + 1; 
            else dp[i][0] = 0;
        }

        for(int i=1;i<m ;i++){
            if(s3[i-1] == s2[i-1]) dp[0][i] = dp[0][i-1] + 1; 
            else dp[0][i] = 0;
        }

        int a = 0, b = 0;

        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(i+j > s3.length()){
                    dp[i][j] = 0;
                    break;
                }
                a = 0; b=0;
                if(s3[i+j-1] == s1[i-1]) a = dp[i-1][j] + 1; 
                if(s3[i+j-1] == s2[j-1]) b = dp[i][j-1] + 1; 
                dp[i][j] = max(a,b);
            }
        }

        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         // if(i==0 && j==0) continue;
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << "" << endl;
        // }

        return dp[n-1][m-1] == s3.length();
    }
};