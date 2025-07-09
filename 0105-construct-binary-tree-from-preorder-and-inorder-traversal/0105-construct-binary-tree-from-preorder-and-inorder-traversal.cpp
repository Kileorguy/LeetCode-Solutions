class Solution {
public:
    unordered_map<int,int> inMap;
    int idx = 0;

    TreeNode *build(vector<int>& preorder, int left, int right){
        if(left > right) return nullptr;

        TreeNode *node = new TreeNode(preorder[idx++]);
        int mid = inMap[node->val];

        node->left = build(preorder, left, mid-1);
        node->right = build(preorder, mid+1, right);

        return node;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int len = preorder.size();
        for(int i=0;i<len;i++){
            inMap[inorder[i]] = i;
        }

        return build(preorder, 0, inorder.size()-1);
    }
};