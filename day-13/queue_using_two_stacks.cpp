

// Solution 1: Using two Stacks where push operation is O(N)
//Solution 2: Using two Stacks where push operation is O(1) and pop function is amortised O(1)

class MyQueue {
public:
    stack<int> input, output;
    MyQueue() {
        
    }
    
    void push(int x) {
        // while(!input.empty()){
        //     output.push(input.top());
        //     input.pop();
        // }
        // input.push(x);
        // while(!output.empty()){
        //     input.push(output.top());
        //     output.pop();
        // }
        // return;
        
        input.push(x);
        return;
    }
    
    int pop() {
        // int ans;
        // if (!input.empty()){
        //     ans=input.top();
        //     input.pop();
        //     return ans;
        // }
        // else{
        //     cout<<"it is empty"<<endl;
        //     return -1;
        // }
        
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
    
    int peek() {
        // int ans=input.top();
        // return ans;
        
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
    
    bool empty() {
        // return input.empty();
        
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