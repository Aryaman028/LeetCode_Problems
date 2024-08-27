class MyStack {
public:
        queue<int>q;
        queue<int>sec;
    MyStack() {
        
    }
    
    void push(int x) {
        while(!q.empty()){
            sec.push(q.front());
            q.pop();
        }
        q.push(x);
        while(!sec.empty()){
            q.push(sec.front());
            sec.pop();
        }
    }
    
    int pop() {
        int val = q.front();
        q.pop();
        return val;
    }
    
    int top() {
        return q.front();
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