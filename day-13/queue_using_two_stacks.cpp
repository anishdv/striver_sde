

// Solution 1: Using two Stacks where push operation is O(N)
//Solution 2: Using two Stacks where push operation is O(1) and pop function is amortised O(1)


// amortised -- when push operation is o(n) , in enqueue operation it is taking 2 push and 2 pop operations and dequeue 0 such operations are there
// but when we say we have amortised time complexity we now use only one push operation for enqueue and 3 for dequeue
class MyQueue {
public:
    stack<int> input, output;
    MyQueue() {
        
    }
    
    void push(int x) { // o(1)
        input.push(x);
        return;
    }
    
    int pop() { // o(1) amortised 
        
        int ans;
        if (output.empty()){
            while(!input.empty()){
                output.push(input.top());
                input.pop();
            }
        }
        ans=output.top();
        output.pop();
        return ans;
    }
    
    int peek() { // o(1) amortised
    
        int ans;
        if (output.empty()){
            while(!input.empty()){
                output.push(input.top());
                input.pop();
            }
        }
        ans=output.top();
        return ans;
    }
    
    bool empty() { // o(1)
        
        return input.empty() && output.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */