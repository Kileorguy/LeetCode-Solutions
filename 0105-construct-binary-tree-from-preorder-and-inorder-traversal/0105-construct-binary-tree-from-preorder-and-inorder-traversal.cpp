class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int len = preorder.size();
        unordered_map<int,int> preMap;
        unordered_map<int,int> inMap;
        for(int i=0;i<len;i++){
            // preMap[preorder[i]] = i;
            inMap[inorder[i]] = i;
        }

        TreeNode *root = new TreeNode(preorder[0]);
        
        for(int i=1;i<len;i++){
            TreeNode *temp = root;
            TreeNode *newNode = new TreeNode(preorder[i]);
            
            while(true){
                if(inMap[newNode->val] < inMap[temp->val]){
                    if(temp->left) temp = temp->left;
                    else break;
                }else{
                    if(temp->right) temp = temp->right;
                    else break;
                }
            }
            
            if(inMap[newNode->val] < inMap[temp->val]){
                temp->left = newNode;
            }else{
                temp->right = newNode;
            }
        }
        return root;
    }
};