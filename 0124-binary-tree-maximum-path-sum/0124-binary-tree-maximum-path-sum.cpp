class Solution {
public:
    int maxPath = INT_MIN;
    
    int dfs(TreeNode *root){
        if(!root) return 0;

        int leftSum = max(dfs(root->left),0);
        int rightSum = max(dfs(root->right), 0);

        maxPath = max(maxPath, leftSum + rightSum + root->val);

        return root->val + max(leftSum, rightSum);
    }

    int maxPathSum(TreeNode* root) {
        dfs(root);
        return maxPath;
    }
};