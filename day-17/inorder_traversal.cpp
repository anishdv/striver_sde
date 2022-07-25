// we have given depth search array
    // ITERATIVE SOLUTION + TC AND SC -O(N)
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack <TreeNode*> st;
        TreeNode* node=root;
        while(true){
            if (node!=NULL){
                st.push(node);
                node=node-> left;
            }
            else{
                if (st.empty()) break;
                node=st.top();
                st.pop();
                ans.push_back(node->val);
                node=node->right;
            }
        }
        return ans;
    }


// RECURSIVE SOLUTION 
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> nodes;
        inorder(root, nodes);
        return nodes;
    }
    void inorder(TreeNode* root, vector<int>& nodes) {
        if (!root) {
            return;
        }
        inorder(root -> left, nodes);
        nodes.push_back(root -> val);
        inorder(root -> right, nodes);
    }
