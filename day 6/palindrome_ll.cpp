// this is solution to https://leetcode.com/problems/palindrome-linked-list/

class Solution {
public:
    ListNode* middle(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head;
        
        while (fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    
    ListNode* reverse(ListNode* head){
        // there are two methods for this once is recursive and other is iterative i gonna use iterative
        ListNode* prev=NULL;
        ListNode* cur=head;
        ListNode* fwd=cur->next;
        
        while (cur!=NULL){
            fwd=cur->next;
            cur->next=prev;
            prev=cur;
            cur=fwd;
        }
        
        return prev;
    }
    
    bool isPalindrome(ListNode* head) {
        // we need to find the middle then we need to reverse the linked list from middle till end
        // then we need to check from start to middle and check with corresponding value from end to middle traversal
        
        // for finding middle element we need to use fast slow pointers
        ListNode* mid=middle(head);
        // Now for reversing 
        ListNode* tail=reverse(mid);
        
        while(tail!=NULL){
            if (head->val!=tail->val){
                return false;
            }
            cout<<head->val<<"matched with"<<tail->val<<" ";
            head=head->next;
            tail=tail->next;
        }
        cout<<endl;
        return true;
        
    }
};