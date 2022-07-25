// this is solution to https://leetcode.com/problems/copy-list-with-random-pointer/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head==NULL) return NULL;
        
        Node* temp=head;
        Node* forw=head->next;
        Node* newNode;
        
        // step 1 -- plugging in the new list nodes in between
        while (forw!=NULL){
            newNode= new Node (temp->val);
            temp->next=newNode;
            newNode->next=forw;
            temp=forw;
            forw=forw->next;
        }
        newNode =new Node (temp->val);
        temp->next=newNode;
        newNode->next=NULL;
        
        // step 2 -- pointing to random in new list
        Node* iter=head;
        while (iter!=NULL){
            if (iter->random ==NULL){
            iter->next->random=iter->random;}
            else{
                iter->next->random=iter->random->next;
            }
            iter=iter->next->next;
        }
        
        // step 3 -- separating both new and old lists
        Node* tempold=head;
        Node* ans=head->next;
        Node* tempNew=head->next;
        forw=head->next->next;
        while (forw!=NULL){
            tempold->next=forw;
            tempNew->next=forw->next;
            tempNew=forw->next;
            tempold=forw;
            forw=forw->next->next;
        }
        tempold->next=NULL;
        return ans;
    }
        
};