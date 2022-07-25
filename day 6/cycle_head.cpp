// this is solution to https://leetcode.com/problems/linked-list-cycle-ii/

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow=head;
        ListNode* fast=head;
        bool detected=false;
        
        while (fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
            if (slow==fast){
                slow=head;
                detected=true;
                break;
            }
        }
        
        if (detected){
        while(slow!=fast){
            slow=slow->next;
            fast=fast->next;
        }
        return slow;}
        return NULL;
    }
};