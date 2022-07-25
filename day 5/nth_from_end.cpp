// this is solution to https://leetcode.com/problems/remove-nth-node-from-end-of-list/


class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* end=head;
        int sz=0;
        
        while (end!=NULL){
            end=end->next;
            sz++;
        }
        
        end=head;
        int cnt=0;
        // edge case
        if (sz==n) return head->next;
        while (cnt<sz-n-1){
            cnt++;
            end=end->next;
        }
        end->next=end->next->next;
    
        return head;}


        ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* start=new ListNode();
        // start is dummy node
        
        start->next=head;
        ListNode* fast=start;
        ListNode* slow=start;
        
        for(int i=1; i<=n ; i++){
            fast=fast->next;
        }
        
        while (fast->next!=NULL){
            slow=slow->next;
            fast=fast->next;
        }
        slow->next=slow->next->next;
        return start->next;
    }
};