class Solution {
public:

    int h[4] = {0,1,0,-1};
    int v[4] = {1,0,-1,0};
    void dfs(vector<vector<int>> &heights, vector<vector<bool>> &vis, int i, int j){
        if(i<0 || j<0 || i >= heights.size() || j >= heights[0].size()) return;
        if(vis[i][j]) return;
        vis[i][j] = true;

        for(int a=0;a<4;a++){
            int ii = i + v[a];
            int jj = j + h[a];

            if(ii>=0 && jj>=0 && ii<heights.size() && jj<heights[0].size() && heights[ii][jj] >= heights[i][j]){
                dfs(heights, vis, ii, jj);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> ans;
        int maxI = heights.size(), maxJ = heights[0].size();
        vector<vector<bool>> visPacific(maxI, vector(maxJ, false));
        vector<vector<bool>> visAtlantic(maxI, vector(maxJ, false));

        for(int i=0;i<maxI;i++){
            for(int j=0;j<maxJ;j++){
                if(i==0 || j==0) dfs(heights, visPacific, i,j);
                if(i==maxI-1 || j==maxJ-1) dfs(heights, visAtlantic, i,j);
            }
        }

        for(int i=0;i<maxI;i++){
            for(int j=0;j<maxJ;j++){
                if(visPacific[i][j] && visAtlantic[i][j]){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;

        
    }
};