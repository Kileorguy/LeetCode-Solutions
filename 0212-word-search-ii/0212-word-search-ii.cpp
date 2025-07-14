
class Solution {
public:

    struct TrieNode{
        TrieNode *node[26];
        TrieNode(){
            for(int i=0;i<26;i++){
                node[i] = nullptr;
            }
        }
    };
    TrieNode *root;

    int h[4] = {0,1,0,-1};
    int w[4] = {1,0,-1,0};

    int sizeI, sizeJ;

    void insertTrie(vector<vector<char>>& board, vector<vector<bool>>& visited, int i, int j, TrieNode *root, int depth = 0){
        if(depth == 10) return;
        if(i < 0 || j < 0 || i >= sizeI || j>=sizeJ) return;
        if(visited[i][j]) return;
        int ascii = toAscii(board[i][j]);

        if(!root->node[ascii]){
            root->node[ascii] = new TrieNode();
        }
        root = root->node[ascii];
        visited[i][j] = true;
        
        for(int x=0;x<4;x++){
            insertTrie(board,visited, i+h[x], j+w[x], root, depth+1);
        }

        visited[i][j] = false;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> ans;
        root = new TrieNode();
        vector<bool> seen(26);
        for(string w: words){
            seen[toAscii(w[0])] = true;
        }

        sizeI =  board.size();
        sizeJ = board[0].size();
        vector<vector<bool>> visited(sizeI, vector<bool>(sizeJ, false));

        for(int i=0;i<sizeI;i++){
            for(int j=0;j<sizeJ;j++){
                if(seen[toAscii(board[i][j])]){
                    TrieNode *temp = root;
                    insertTrie(board, visited, i,j, temp);
                }
            }
        }

        for(string w: words){
            TrieNode *temp = root;
            bool check = true;
            for(char c: w){
                int ascii = toAscii(c);
                if(temp->node[ascii]){
                    temp = temp->node[ascii];
                }else{
                    check = false;
                    break;
                }
            }
            if(check) ans.push_back(w);
        }
        return ans;


    }
private:
    int toAscii(char a){
        return (int)a - (int)'a';
    }
};
