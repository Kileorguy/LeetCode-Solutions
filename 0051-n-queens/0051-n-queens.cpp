class Solution {
public:
    void init_map(vector<string> &map, int &n){
        string temp ="";
        for(int i=0;i<n;i++){
            temp += ".";
        }
        
        for(int i=0;i<n;i++){
            map.push_back(temp);
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;

        
        vector<string> map;
        init_map(map, n);
        backtrack(ans, map, 0, n, 0);
        return ans;
    }
private:
    bool check(int &ii, int &jj, vector<string> &map, int &n){
        // check up
        int i, j;
        for(i=0;i<ii;i++){
            if(map[i][jj] == 'Q') return false;
        }
        // check left diag
        i = ii; j = jj;
        while(i > 0 && j > 0){
            i --;
            j --;
            if(map[i][j] == 'Q') return false;
        }
        i = ii; j = jj;
        // check right diag
        while(i > 0 && j < n-1){
            i --;
            j ++;
            if(map[i][j] == 'Q') return false;
        }

        return true;
    }
    void backtrack(vector<vector<string>> &ans, vector<string> &map, int depth, int n, int count){

        if(count == n){
            ans.push_back(map);
            return;
        }

        string &curr = map[depth];
        for(int i=0;i<n;i++){
            if(check(depth,i, map, n)){
                curr[i] = 'Q';
                backtrack(ans, map, depth+1, n, count+1);
                curr[i] = '.';
            }
        }
    }
};