 
 // we will use threaded binary tree method which is used in morris traversal 
    // tc -o (n) and sc- o(1)
    
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode* cur=root;
        vector<int> ans;
        while(cur!=NULL){
            if (cur->left==NULL){
                ans.push_back(cur->val);
                cur=cur->right;
            }
            else{
                TreeNode* prev= cur->left;
                while(prev->right && prev->right != cur){
                    prev=prev->right;
                }
                if (prev->right==NULL){ // thread formation time
                    prev->right=cur;
                    cur=cur->left;
                }
                else{ // cur is reached to parent node and left part is done so it needs to be inserted 
                    prev->right=NULL;
                    ans.push_back(cur->val);
                    cur=cur->right;
                }
            }
        }
        return ans;
    }