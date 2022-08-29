//https://leetcode.com/problems/populating-next-right-pointers-in-each-node/

class Solution {
public:
    // tc -o(n) sc-o(n)
    Node* connect(Node* root) {
        if(!root)return root;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                Node* x=q.front();
                q.pop();
                if(i!=n-1)x->next=q.front();
                if(x->left)q.push(x->left);
                if(x->right)q.push(x->right);
            }
        }
        return root;
    }


    // tc - o(n) and sc -o(1)
    Node* connect(Node* root) {
        auto head = root;
        for(; root; root = root -> left) 
            for(auto cur = root; cur; cur = cur -> next)   // traverse each level - it's just BFS taking advantage of next pointers          
                if(cur -> left) {                          // update next pointers of children if they exist               
                    cur -> left -> next = cur -> right;
                    if(cur -> next) cur -> right -> next = cur -> next -> left;
                }
                else break;                                // if no children exist, stop iteration                                                  
        
        return head;
    }
};