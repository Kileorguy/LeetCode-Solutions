class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        queue<TreeNode*> q; 
        q.push(root);
        // ans.push_back(root->val);

        while(!q.empty()){
            int len = q.size();
            
            TreeNode *node;
            for(int i=0;i<len;i++){
                node = q.front();
                q.pop();

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            if(node) ans.push_back(node->val);

        }
        return ans;

    }
};