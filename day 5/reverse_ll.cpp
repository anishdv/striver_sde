// this is solution to https://leetcode.com/problems/reverse-linked-list/

class Solution {
public:
    // iterative solution-- using prev cur next-- 3 pointer approach
    ListNode* reverseList(ListNode* head) {
        
        ListNode* prev=NULL;
        ListNode* cur=head;
        ListNode* forw;
        
        while(cur!=NULL){
            forw=cur->next;
            cur->next=prev;
            prev=cur;
            cur=forw;
        }
        return prev;
    }
     void solve(ListNode* &head, ListNode* cur, ListNode* prev){
         if(cur==NULL){
             head=prev;
             return;
         }
         solve(head, cur->next, cur);
         cur->next=prev;
         return;
     }
     ListNode* reverseList(ListNode* head){
         ListNode* curr=head;
         ListNode* prev=NULL;
         solve(head, curr, prev);
         return head;
     }
};