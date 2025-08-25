class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<vector<int>> dp(2, vector<int>(n,0));

        if(s[0] != '0') dp[0][0] = 1;

        for(int i=0;i<n-1;i++){

            if(s[i+1] != '0'){
                dp[0][i+1] += dp[0][i];
                dp[0][i+1] += dp[1][i];
            }

            if(s[i] == '0'){
                dp[1][i+1] = 0;
            }else if(stoi(s.substr(i,2)) <= 26){
                dp[1][i+1] += dp[0][i];
            }
        }
        return dp[0][n-1] + dp[1][n-1];
    }
};