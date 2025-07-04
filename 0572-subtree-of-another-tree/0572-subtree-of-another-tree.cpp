class Solution {
public:

    bool checkSame(TreeNode *p, TreeNode *sub){
        if(!p || !sub){
            if(!p && !sub) return true;
            return false;
        }
        
        return p->val == sub->val && checkSame(p->left, sub->left) 
                && checkSame(p->right, sub->right);
    }

    bool same = false;
    void dfs(TreeNode *root, TreeNode *subRoot){
        if(!root) return;

        if(root->val == subRoot->val){
            if(checkSame(root, subRoot)) same = true;
        }

        if(!same){
            dfs(root->left, subRoot);
            dfs(root->right, subRoot);
        }
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        dfs(root,subRoot);
        return same;
    }
};