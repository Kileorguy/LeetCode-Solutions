class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";
        queue<TreeNode*> q;
        q.push(root);
        string res = to_string(root->val).append(";");
        while(!q.empty()){
            TreeNode *curr = q.front();
            q.pop();

            if(curr && curr->left) {
                q.push(curr->left);
                res.append(to_string(curr->left->val).append(";"));
            }else{
                res.append("null;");
            }
            if(curr && curr->right) {
                q.push(curr->right);
                res.append(to_string(curr->right->val).append(";"));
            }else{
                res.append("null;");
            }
        }

        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        cout << data << endl;
        if(data == "") return nullptr;
        vector<string> sList = split(data, ';');
        int len = sList.size();

        cout << sList[0] << endl;
        cout << "======" << endl;
        TreeNode *root = new TreeNode(stoi(sList[0]));
        queue<TreeNode*> q;
        q.push(root);

        for(int i=1;i<len;i++){
            TreeNode *curr = q.front();
            q.pop();
            cout << sList[i] << endl;
            if(sList[i] != "null"){
                curr->left = new TreeNode(stoi(sList[i]));
                q.push(curr->left);
            }
            i++;
            cout << sList[i] << endl;

            if(sList[i] != "null"){
                curr->right = new TreeNode(stoi(sList[i]));
                q.push(curr->right);
            }
        }
        return root;
        
    }
private:
    vector<string> split(const string& str, char delimiter) {
        vector<string> tokens;
        stringstream ss(str);
        string token;

        while (getline(ss, token, delimiter)) {
            tokens.push_back(token);
        }

        return tokens;
    }
};