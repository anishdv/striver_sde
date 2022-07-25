//https://leetcode.com/problems/binary-tree-right-side-view/

void help(TreeNode* root, int  level, vector<int> &v){
        if (root==NULL) return;
        if (v.size()==level){
            v.push_back(root->val);
        }
        help(root->right,level+1,v);
        help(root->left, level+1,v);
        return;
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if (root==NULL) return ans;
        help(root, 0, ans);
        return ans;
    }