 //https://leetcode.com/problems/binary-tree-preorder-traversal/
 
 vector<int> preorderTraversal(TreeNode* root) {
         vector<int> ans;
        if (root==NULL) return ans;
        
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            root=st.top();
            ans.push_back(root->val);
            st.pop();
            // first right then left because we want left right
            if (root->right!=NULL) st.push(root->right);
            if (root->left!=NULL) st.push(root->left);
            
        }
        return ans;
    }