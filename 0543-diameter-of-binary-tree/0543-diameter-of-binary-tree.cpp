class Solution {
public:

    int maxDiam = 0;
    
    int dfs(TreeNode *root){
        if(!root) return 0;
        
        int hLeft = dfs(root->left);
        int hRight = dfs(root->right);

        maxDiam = max(hLeft + hRight, maxDiam);

        return 1 + max(hLeft, hRight);

    }

    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return maxDiam;
    }
};