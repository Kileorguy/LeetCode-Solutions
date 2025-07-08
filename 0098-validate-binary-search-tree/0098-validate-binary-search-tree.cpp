class Solution {
public:

    long long int prev = LLONG_MIN;
    bool check = true;
    void dfs(TreeNode *root, bool first){
        if(!root || !check) return;

        dfs(root->left, false);

        // cout << prev << " " + to_string(root->val) << endl;
        if(prev >= root->val) check = false; 
        prev = root->val;

        dfs(root->right, false);
    }

    bool isValidBST(TreeNode* root) {
        dfs(root,true);
        return check;
    }
};