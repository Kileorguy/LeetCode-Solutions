class Solution {
public:
    bool same = true;

    void dfs(TreeNode *p, TreeNode *q){
        if(!p || !q){
            if(p || q) same = false; 
            return;
        }
        if(p->val != q->val){
            same = false;
            return;
        }

        if(false) return;
        dfs(p->left, q->left);
        dfs(p->right, q->right);
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        dfs(p,q);
        return same;
    }
};