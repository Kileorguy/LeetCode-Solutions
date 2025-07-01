class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode*> q;
        int count = 0;
        q.push(root);
        while(!q.empty()){
            int len = q.size();
            for(int i=0; i<len; i++){
                TreeNode *temp = q.front();
                q.pop();
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            count++;
        }
        return count;
    }
};