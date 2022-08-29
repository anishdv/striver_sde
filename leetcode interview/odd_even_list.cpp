//https://leetcode.com/problems/odd-even-linked-list/

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode* temp=head;
        
        // base cases
        if (head==NULL) return head;
        if(head->next==NULL) return head;
        
        // initialisation of variables
        ListNode* fwd=head->next;
        ListNode* head1=head;
        ListNode* head2=head->next;
        
        // so that we can predict which group's last will point to NULL
        // we dont want the odd part's end to point NULL
        int cnt1=1;
        int cnt2=0;
        
        
        while(fwd){
            if ((cnt1+cnt2)%2!=0){
                temp->next=fwd->next;
                cnt1++;
                if(fwd->next==NULL){
                    temp->next= head2;
                    break;
                }
                temp=fwd;
                fwd=fwd->next;
            }
            else{
                temp->next=fwd->next;
                cnt2++;
                if (fwd->next==NULL){
                    fwd->next=head2;
                    break;
                }
                temp=fwd;
                fwd=fwd->next;
            }
        }
        return head1;
    }
};