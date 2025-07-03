class Solution {
public:

    int getHeight(TreeNode* root){
        if(!root) return 0;
        return 1 + max(getHeight(root->left), getHeight(root->right));
    }

    bool dfs(TreeNode *root){
        if(!root) return true;

        int hL = getHeight(root->left);
        int hR = getHeight(root->right);

        return abs(hL - hR) <= 1 && dfs(root->left) && dfs(root->right); 
    }

    bool isBalanced(TreeNode* root) {
        return dfs(root);
    }   
};