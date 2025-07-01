class Solution {
public:
    TreeNode *dfs(TreeNode *root){
        if(!root) return nullptr;

        dfs(root->left);
        dfs(root->right);
        
        if(root->left || root->right){
            TreeNode *temp = root->left;
            root->left = root->right;
            root->right = temp;
        }

        return root;
    }

    TreeNode* invertTree(TreeNode* root) {
        return dfs(root);
    }
};