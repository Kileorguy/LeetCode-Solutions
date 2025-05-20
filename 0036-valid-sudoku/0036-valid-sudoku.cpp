class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> row[9];
        unordered_set<char> col[9];
        unordered_set<char> box[9];
        int boxIndex; 
        char val;
        for(int r=0; r<9;r++){
            for(int c=0; c<9; c++ ){
                // cout << r;
                // cout << c << endl;
                if(board[r][c]=='.') continue;
                val = board[r][c];
                boxIndex = (r / 3)*3 + (c/3);

                if(row[r].count(val) || col[c].count(val) || box[boxIndex].count(val)){
                    return false;
                }

                row[r].insert(val);
                col[c].insert(val);
                box[boxIndex].insert(val);

            }
        }
        return true;
    }
};