class Solution {
public:
    bool found = false;
    int iSize = 0, jSize = 0;

    int h[4] = {0, 0, 1, -1};
    int v[4] = {1, -1, 0, 0};

    void backtrack(vector<vector<char>> &board, string &word, int idx, int i, int j, int maxLen) {
        if (found) return;
        if (idx == maxLen) {
            found = true;
            return;
        }

        char prev = board[i][j];
        board[i][j] = '-';

        for (int a = 0; a < 4; a++) {
            int new_i = i + v[a];
            int new_j = j + h[a];

            if (new_i >= 0 && new_j >= 0 && new_i < iSize && new_j < jSize &&
                board[new_i][new_j] == word[idx]) {
                backtrack(board, word, idx + 1, new_i, new_j, maxLen);
            }
        }

        board[i][j] = prev;
    }

    bool exist(vector<vector<char>> &board, string word) {
        iSize = board.size();
        jSize = board[0].size();

        for (int i = 0; i < iSize; i++) {
            for (int j = 0; j < jSize; j++) {
                if (board[i][j] == word[0]) {
                    backtrack(board, word, 1, i, j, word.length());
                    if (found) return true; 
                }
            }
        }

        return found;
    }
};
