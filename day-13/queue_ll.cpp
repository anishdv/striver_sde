// https://practice.geeksforgeeks.org/problems/implement-queue-using-linked-list/1

void MyQueue:: push(int x)
{
        // Your Code
        QueueNode* newNode= new QueueNode(x);
        newNode->next=NULL;
        if (front==NULL){
            front=newNode;
            rear=newNode;
        }
        else{
            rear->next= newNode;
            rear=newNode;
        }
        return;
}

//Function to pop front element from the queue.
int MyQueue :: pop()
{
        // Your Code    
        if (front==NULL) return -1;
        else{
            int val=front->data;
            front=front->next;
            if (front==NULL) rear=NULL;
            return val;
        }
        
}