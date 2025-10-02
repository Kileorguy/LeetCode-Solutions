class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<bool>> vis(n, vector<bool>(n, false));

        using T = tuple<int,int,int>;
        priority_queue<T, vector<T>, greater<T>> pq;

        pq.push({grid[0][0], 0, 0});
        int ans = 0;

        int dirs[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};

        while (!pq.empty()) {
            auto [weight, i, j] = pq.top(); pq.pop();

            if (vis[i][j]) continue;
            vis[i][j] = true;

            ans = max(ans, weight);

            if (i == n-1 && j == n-1) return ans;

            for (auto& d : dirs) {
                int ii = i + d[0];
                int jj = j + d[1];
                if (validate(ii, jj, n) && !vis[ii][jj]) {
                    pq.push({grid[ii][jj], ii, jj});
                }
            }
        }
        return ans; 
    }
private:
    bool validate(int i, int j, int n) {
        return i >= 0 && i < n && j >= 0 && j < n;
    }
};
