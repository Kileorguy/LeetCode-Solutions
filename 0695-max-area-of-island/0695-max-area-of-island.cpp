class Solution {
public:
    int floodfill(int i, int j, vector<vector<int>> &grid, int &maxI, int &maxJ){
        // cout << i << " " << j << endl;
        if(i < 0 || j < 0 || i >= maxI || j >= maxJ) return 0;
        if(grid[i][j] == 0) return 0;
        grid[i][j] = 0;

        return 1 + floodfill(i,j+1, grid, maxI, maxJ)+ floodfill(i,j-1, grid, maxI, maxJ)+ floodfill(i+1,j, grid, maxI, maxJ)+ floodfill(i-1,j, grid, maxI, maxJ);
        
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxI = grid.size(), maxJ = grid[0].size();
        int ans = INT_MIN;
        for(int i=0;i<maxI;i++){
            for(int j=0;j<maxJ;j++){
                if(grid[i][j] == 1) ans = max(ans, floodfill(i, j, grid, maxI, maxJ));
            }
        }
        return max(ans,0);
    }
};