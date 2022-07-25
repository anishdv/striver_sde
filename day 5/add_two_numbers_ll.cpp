// this is solution to https://leetcode.com/problems/add-two-numbers/

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
        ListNode* dummy= new ListNode();
        ListNode* ans=dummy;
        
        while(l1 || l2 || carry){
            int sum=0;
            if (l1!=NULL){
                sum+=l1->val;
                l1=l1->next;
            }
            if (l2!=NULL){
                sum+=l2->val;
                l2=l2->next;
            }
            sum+=carry;
            ListNode* temp= new ListNode(sum%10);
            carry =sum/10;
            ans->next=temp;
            ans=temp;
        }
        return dummy->next;
    }
};