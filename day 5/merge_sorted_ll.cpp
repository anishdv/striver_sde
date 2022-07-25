// this is solution to https://leetcode.com/problems/merge-two-sorted-lists/

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head=NULL;
        ListNode* temp=NULL;
        if(list1==NULL) return list2;
        if (list2==NULL) return list1;
        
        if (list1->val<list2->val){
            head=list1;
            temp=list1;
            list1=list1->next;
        }
        else{
            head=list2;
            temp=list2;
            list2=list2->next;
        }
        // temp is lastly filled node
        while(list1!=NULL && list2!=NULL){
            if (list1->val<list2->val){
                temp->next=list1;
                list1=list1->next;
            }
            else{
                temp->next=list2;
                list2=list2->next;
            }
            temp=temp->next;
        }
        
        if (list1!=NULL){
            temp->next=list1;
            list1=list1->next;
        }
        if(list2!=NULL){
            temp->next=list2;
        }
        return head;
    }
};