// this is solution to https://leetcode.com/problems/intersection-of-two-linked-lists/



class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//          //two loops-O(m+n) and using extra space
        unordered_map<ListNode*, int> mp;
        // address and its count will be stored
        ListNode* tempA=headA;
        ListNode* tempB=headB;
        
        while (tempA!=NULL){
            mp[tempA]=1;
            tempA=tempA->next;
        }
        
        while (tempB!=NULL){
            if (mp.find(tempB)!=mp.end()){
                return tempB;
            }
            tempB=tempB->next;
        }
        return NULL;
         
         // no space but change in linked list and then erase those changes
        ListNode* tempA=headA;
        ListNode* tempB=headB;
        ListNode* ans=NULL;
        
        while(tempA!=NULL){
            tempA->val*=-1;
            tempA=tempA->next;
        }
        while (tempB!=NULL){
            tempB->val*=-1;
            if (tempB->val > 0){
                ans=tempB;
                break;
            }
            tempB=tempB->next;
        }
        tempA=headA;
        tempB=headB;
        
        while (tempA!=NULL){
            if (tempA->val < 0){
                tempA->val *= -1;}
            tempA=tempA->next;
            
        }
        while (tempB!=NULL){
            if (tempB->val < 0){
                tempB->val *= -1;}
            tempB=tempB->next;
            
        }
        return ans;


        // difference of length method ...ll having more elements in front part will come upto same distant elenent from intersection point
         int diff = getDifference(headA,headB);
        if(diff < 0) 
            while(diff++ != 0) headB = headB->next; 
        else while(diff-- != 0) headA = headA->next;
        while(headA != NULL) {
            if(headA == headB) return headA;
            headB = headB->next;
            headA = headA->next;
        }
        return headA;

    }
        int getDifference(ListNode* headA,ListNode* headB) {
     int lenA = 0,lenB = 0;
        while(headA != NULL || headB != NULL) {
            if(headA != NULL) {
                ++lenA; headA = headA->next;
            }
            if(headB != NULL) {
                ++lenB; headB = headB->next;
            }
            
        }
        return lenA-lenB;//if difference is neg-> length of list2 > length of list1 else vice-versa
}
};