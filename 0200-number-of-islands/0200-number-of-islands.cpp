class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;

        int sizeI = grid.size(), sizeJ = grid[0].size();

        for(int i=0;i<sizeI;i++){
            for(int j=0;j<sizeJ;j++){
                if(grid[i][j] == '1'){
                    count++;
                    floodfill(grid, i, j, sizeI, sizeJ);
                }
            }
        }


        return count;
    }
private:
    void floodfill(vector<vector<char>> &grid, int i, int j, int &sizeI, int &sizeJ){
        if(i < 0 || j < 0 || i >= sizeI || j>=sizeJ) return;
        if(grid[i][j] == '0' || grid[i][j] == 'x') return;
        grid[i][j]='x';
        floodfill(grid, i+1, j, sizeI,sizeJ);
        floodfill(grid, i, j+1, sizeI,sizeJ);
        floodfill(grid, i-1, j, sizeI,sizeJ);
        floodfill(grid, i, j-1, sizeI,sizeJ);
    }
};