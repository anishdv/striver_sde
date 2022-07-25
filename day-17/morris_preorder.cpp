// we will use threaded binary tree method which is used in morris traversal 
    // tc -o (n) and sc- o(1)
    
    vector<int> preorderTraversal(TreeNode* root) {
         vector<int> ans;
        TreeNode* cur=root;
        while(cur!=NULL){
            if (cur->left==NULL){
                ans.push_back(cur->val);
                cur=cur->right;
            }
            else{
                TreeNode* prev= cur->left;
                while(prev->right && prev->right !=cur){
                    prev=prev->right;
                }
                
                if (prev->right==NULL){// thread formation time
                    prev->right=cur;
                    ans.push_back(cur->val);
                    cur=cur->left;
                }
                else{ // thread removal time 
                    prev->right =NULL;
                    cur=cur->right;
                }
            }
        }
        return ans;
    }