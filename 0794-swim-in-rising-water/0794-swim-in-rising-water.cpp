class Solution {
public:
    int h[4] = {0,1,0,-1};
    int v[4] = {1,0,-1,0};
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<bool>> vis(n, vector<bool>(n, false));

        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;

        // weight, i, j
        pq.push({grid[0][0],0,0});

        vector<int> curr = pq.top();
        int weight = curr[0],i=curr[1],j=curr[2];

        int ans = weight;

        while (i!=n-1 || j!=n-1) {
            curr = pq.top(); pq.pop();
            weight = curr[0];
            ans = max(ans, weight);
            i=curr[1], j=curr[2];

            vis [i][j] = true;

            for (int a=0; a < 4; a++) {
                int ii = i + v[a];
                int jj = j + h[a];

                if (validate(ii,jj,n) && !vis[ii][jj]) {
                    pq.push({grid[ii][jj],ii,jj});
                }
            }
        }
        return ans;
    }
private:
    bool validate(int &i, int &j, int &n) {
        return i >= 0 && i < n && j >= 0 && j < n;
    }
};