class Solution {
public:
    int height(TreeNode *root){
        if(!root) return 0;
        return 1 + max(height(root->left), height(root->right));
    }

    int dfs(TreeNode *root){
        if(!root) return 0;
        
        int h = height(root->left) + height(root->right);
        int diamLeft = dfs(root->left);
        int diamRight = dfs(root->right);
        return max(max(h, diamLeft), diamRight);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int res = dfs(root);
        if(res == -1) return 0;
        return res;
    }
};