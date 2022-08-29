class Solution {
public:


//  recursive approach tc-o(n) and sc-o(logn)
    TreeNode* bstFromPreorder(vector<int>& A) {
        int i = 0;
        return build(A, i, INT_MAX);
    }

    TreeNode* build(vector<int>& A, int& i, int bound) {
        if (i == A.size() || A[i] > bound) return NULL;
        TreeNode* root = new TreeNode(A[i++]);
        root->left = build(A, i, root->val);
        root->right = build(A, i, bound);
        return root;
    }
    
    

    // iterative approach tc-o(n) and sc-o(logn)
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode dummy_root(INT_MAX);
        stack<TreeNode *> s({&dummy_root});
        for (int x : preorder) {
            auto n = new TreeNode(x);
            TreeNode *p = nullptr;
            while (s.top()->val < x) {
                p = s.top();
                s.pop();
            }
            if (p) {
                p->right = n;
            } else {
                s.top()->left = n;
            }
            s.push(n);
        }
        return dummy_root.left;
    }
};