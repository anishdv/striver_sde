// this is solution to https://leetcode.com/problems/reverse-nodes-in-k-group/

class Solution {
public:
    ListNode* reverse(ListNode* head, ListNode* prev, int k , int sz){
        ListNode* fwd=head;
        ListNode* cur=head;
        if (sz/k >=1){
            for (int i=0; i<k ; i++){
                fwd=cur->next;
                cur->next=prev;
                prev=cur;
                cur=fwd;
            }

            
            head->next=reverse(cur, NULL, k , sz-k);
            return prev ;
        }
        else{
            return head;
        }
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        // recursion is used and we will see sz/k >=1 or not everytime
        if (k==1) return head;
        int sz=0;
        ListNode* temp=head;
        while (temp!=NULL){
            temp=temp->next;
            sz++;
        }
        return reverse(head, NULL, k,sz);
    }
};