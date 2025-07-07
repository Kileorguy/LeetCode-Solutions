class Solution {
public:
    int count = 0;

    void dfs(TreeNode *root, int maxVal){
        if(!root) return;
        
        if(root->val >= maxVal) count++;
        dfs(root->left, max(maxVal, root->val));
        dfs(root->right, max(maxVal, root->val));
    }

    int goodNodes(TreeNode* root) {
        if(!root) return 0;
        dfs(root, INT_MIN);
        return count;
    }
};