class Solution {
public:

    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int maxI = grid.size();
        int maxJ = grid[0].size();
        bool rot = false;

        for(int i=0;i<maxI;i++){
            for(int j=0;j<maxJ;j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                    rot = true;
                }
            }
        }
        
        int h[4] = {1,0,-1,0};
        int v[4] = {0,1,0,-1};

        int count = 0;
        pair<int,int> p;

        while(!q.empty()){
            int size = q.size();
            count++;
            for(int i=0;i<size;i++){
                p = q.front(); q.pop();
                
                for(int j=0;j<4;j++){
                    int newI = p.first + v[j];
                    int newJ = p.second + h[j];
                    if(newI >= 0 && newJ >= 0 && newI < maxI && newJ < maxJ && grid[newI][newJ] == 1){
                        grid[newI][newJ] = 2;
                        q.push({newI, newJ});
                    }
                }
            }

            
        }

        for(int i=0;i<maxI;i++){
            for(int j=0;j<maxJ;j++){
                if(grid[i][j]==1) return -1;
            }
        }
        if(!rot) return 0;

        return count-1;
        
    }
};