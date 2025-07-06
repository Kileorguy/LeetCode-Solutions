class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;

        vector<int> iter;
        queue<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            int len = st.size();
            iter.clear();
            // cout << "Length " << len << endl;
            for(int i=0;i<len;i++){
                TreeNode *node = st.front();
                
                iter.push_back(node->val);
                
                st.pop();

                if(node->left) {
                    st.push(node->left);
                    // cout << node->left->val << endl;
                }
                if(node->right){
                     st.push(node->right);
                    //  cout << node->right->val << endl;
                }
            }
            ans.push_back(iter);
        }
        return ans;
    }
};