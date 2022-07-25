//https://leetcode.com/problems/min-stack/

class MinStack {
public:
    stack<int> nums;
    stack<int> mins;
    
    
    MinStack() {
        mins.push(INT_MAX);
    }
    
    void push(int val) { // pushing it in nums is obvious we need to check for mins also
        if (mins.top()>=val){
            mins.push(val);
        }
        nums.push(val);
       
    }
    
    void pop() { // popping it from nums is obvious but we need to check whether we need to pop it from mins or not
        if (mins.top()==nums.top()){
            mins.pop();
        }
        nums.pop();
    }
    
    int top() {
        return nums.top();
    }
    
    int getMin() {
        return mins.top();
    }
};