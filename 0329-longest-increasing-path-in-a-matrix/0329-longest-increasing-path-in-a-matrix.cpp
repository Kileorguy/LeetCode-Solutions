class Solution {
public:
    int maxI, maxJ;

    vector<vector<int>> dirs = {{0,1},{1,0},{-1,0}, {0,-1}};

    int dfs(int i, int j, long long int prev, vector<vector<int>> &matrix, vector<vector<int>> &dp){
        if(i < 0 || j < 0 || i>=maxI || j>=maxJ) return 0;

        if(matrix[i][j] >= prev) return 0;
        if(dp[i][j]!=-1) return dp[i][j];

        int maxVal = INT_MIN;
        for(auto &d: dirs){
            maxVal = max(dfs(i+d[0], j+d[1], matrix[i][j], matrix,dp), maxVal);
        }

        dp[i][j] = maxVal + 1;
        return maxVal+1;

        
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        maxI = matrix.size();
        maxJ = matrix[0].size();

        vector<vector<int>> dp(maxI, vector<int>(maxJ, -1));
        int ans = INT_MIN;
        for(int i=0;i<maxI;i++){
            for(int j=0;j<maxJ;j++){
                dp[i][j] = dfs(i,j, LLONG_MAX, matrix, dp);
                ans = max(ans, dp[i][j]);
            }
        }

        return ans;


    }
};