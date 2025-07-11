class Trie {
public:

    struct TrieNode{
        char val; 
        bool endWord;
        TrieNode *Node[26];
        
        TrieNode(): val('\0'), endWord(false){
            for(int i=0;i<26;i++){
                Node[i] = nullptr;
            }
        }

        TrieNode(char v): val(v), endWord(false){
            for(int i=0;i<26;i++){
                Node[i] = nullptr;
            }
        }
    };
    TrieNode *root;

    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode *temp = root;
        for(char c: word){
            int ascii = asciiConvert(c);
            if(!temp->Node[ascii]){
                temp->Node[ascii] = new TrieNode(c);
            }
            temp = temp->Node[ascii];
        }

        temp->endWord = true;
        
    }
    
    bool search(string word) {
        TrieNode *temp = root;

        for(char c: word){
            int ascii = asciiConvert(c);
            if(!temp->Node[ascii]){
                return false;
            }
            temp = temp->Node[ascii];
        }
        if(temp->endWord) return true;
        return false;
    }
    
    bool startsWith(string prefix) {
        TrieNode *temp = root;

        for(char c: prefix){
            int ascii = asciiConvert(c);
            if(!temp->Node[ascii]){
                return false;
            }
            temp = temp->Node[ascii];
        }
        return true;
    }

private:
    int asciiConvert(char x){
        return (int)x - (int)'a';
    }
};