class Solution {
public:

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int h[4] = {1,0,-1,0};
        int v[4] = {0,1,0,-1};
        vector<int> ans;

        int maxI = matrix.size(), maxJ = matrix[0].size();

        vector<vector<bool>> visit(maxI,vector<bool>(maxJ,false));
        int i=0, j=0, dir=0;
        int ii,jj;

        for(int a=0;a<maxI*maxJ;a++){
            visit[i][j]=true;
            ans.push_back(matrix[i][j]);

            ii = i + v[dir];
            jj = j + h[dir];
            if(ii >= 0 && ii < maxI && jj >= 0 && jj < maxJ && !visit[ii][jj]){
                i = ii; j = jj;
            }else{
                dir++;
                dir = dir % 4;
                i += v[dir];
                j += h[dir];
                
            }
        }

        return ans;


    }
};