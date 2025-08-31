class Solution {
public:
    struct Node {
        Node *child[26];
        bool isWord;
        Node() {
            for (int i = 0; i < 26; i++) child[i] = nullptr;
            isWord = false;
        }
    };

    Node *root;

    void insertTrie(const string &word) {
        Node *temp = root;
        for (char c : word) { 
            int idx = c - 'a';
            if (!temp->child[idx]) temp->child[idx] = new Node();
            temp = temp->child[idx];
        }
        temp->isWord = true;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        root = new Node();

        // Build trie
        for (string &w : wordDict) insertTrie(w);

        int n = s.size();
        vector<bool> dp(n + 1, false);  
        dp[0] = true; 

        for (int i = 0; i < n; i++) {
            if (!dp[i]) continue; 

            Node *temp = root;
            for (int j = i; j < n; j++) {
                int idx = s[j] - 'a';
                if (!temp->child[idx]) break; 
                temp = temp->child[idx];
                if (temp->isWord) {
                    dp[j + 1] = true; 
                }
            }
        }

        return dp[n];
    }
};
