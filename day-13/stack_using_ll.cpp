//https://practice.geeksforgeeks.org/problems/implement-stack-using-linked-list/1

void MyStack ::push(int x) 
{
    StackNode* newNode= new StackNode(x);
    newNode->next= top;
    top= newNode;
    return;
}

//Function to remove an item from top of the stack.
int MyStack ::pop() 
{
    if (top==NULL) return -1;
    StackNode* delNode=top;
    top=top->next;
    delNode->next=NULL;
    return delNode->data;
}