class WordDictionary {
public:
    struct TrieNode{
        bool endWord;
        TrieNode *node[26];
        char debug;

        TrieNode(char c){
            endWord = false;
            debug = c;
            for(int i=0;i<26;i++){
                node[i] = nullptr;
            }
        }
    };
    TrieNode *root;

    WordDictionary() {
        root = new TrieNode('-');
        
    }
    
    void addWord(string word) {
        TrieNode *temp = root;
        for(char c: word){
            int idx = (int)c - (int)'a';
            if(!temp->node[idx]){
                temp->node[idx] = new TrieNode(c);
            }
            temp = temp->node[idx];
        }
        temp->endWord = true;
    }
    
    bool search(string word) {
        root->endWord = false;
        int wordLen = word.length();
        TrieNode *temp = root;
        queue<TrieNode*> q;
        q.push(temp);

        for(int i=0; i<wordLen-1; i++){
            char c = word[i];
            int qLen = q.size();
            if(qLen == 0) return false;
            
            for(int i=0; i<qLen ; i++){
                temp = q.front();
                q.pop();

                if(c != '.'){
                    if(temp->node[charToInt(c)]){
                        q.push(temp->node[charToInt(c)]);
                    }
                }else{
                    for(int i=0;i<26;i++){
                        if(temp->node[i]){
                            q.push(temp->node[i]);
                        }
                    }
                }
            }
        }

        int qLen = q.size();
        if(qLen == 0) return false;
        char lastChar = word[wordLen-1];

        for(int i=0;i<qLen;i++){
            temp = q.front();
            q.pop();
            
            if(lastChar == '.'){
                for(int i=0;i<26;i++){
                    if(temp->node[i]){
                        if(temp->node[i]->endWord) return true;
                    }
                }
            }else{
                if(temp->node[charToInt(lastChar)]){
                    if(temp->node[charToInt(lastChar)]->endWord) return true;
                }
            }
        }
        return false;
        
    }
    

private:
    int charToInt(char a){
        return (int)a - (int)'a';
    }
};