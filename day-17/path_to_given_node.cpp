bool helper(TreeNode* A, int B , vector<int> &ans){
    if(!A) return false;
    if (A->val==B){
        ans.push_back(A->val);
        return true;
    }
    ans.push_back(A->val);
    if(helper(A->left, B, ans)|| helper(A->right, B, ans)) return true;
    else {
    ans.pop_back();
    return false;
    }
}
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> ans;
    helper(A,B, ans);
    return ans;
}