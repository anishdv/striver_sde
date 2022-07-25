// this is solution to https://leetcode.com/problems/implement-stack-using-queues/


class MyStack {
public:
    queue<int> q;
    MyStack() {
    }
    
    void push(int x) {
        int s=q.size();
        q.push(x);
        for (int i=0; i<s; i++){
            q.push(q.front());
            q.pop();
        }
        return;
    }
    
    int pop() {
        int ans=q.front();
        q.pop();
        return ans;
    }
    
    int top() {
        int ans=q.front();
        return ans;
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */