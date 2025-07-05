class Solution {
public:

    bool search(TreeNode *root, TreeNode *s){
        if(!root) return false;

        if(root->val == s->val) return true;
        else if(root->val > s->val) return search(root->left, s);
        else if(root->val < s->val) return search(root->right, s);
        return false;
    }

    TreeNode *ans; 

    void dfs(TreeNode *root, TreeNode *p, TreeNode *q){
        if(!root) return;

        if(ans) return;
        dfs(root->left, p, q);
        dfs(root->right, p, q);

        // cout << root->val << " " + to_string(p->val) << " " + to_string(search(root,p)) << endl;
        // cout << root->val << " " + to_string(q->val) << " " + to_string(search(root,q))<< endl;
        // cout << "=========" << endl;
        if(search(root,p) && search(root,q) && !ans) ans = root;
        // else ans = nullptr;

    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p, q);
        return ans;
    }
};