class MyQueue {
public:
    stack<int>res;
    stack<int>sec;
    int val;
    MyQueue() {
    }
    
    void push(int x) {
        res.push(x);            //O(1)
        
    }
    
    int pop() {
        while(!res.empty()){
            sec.push(res.top());
            res.pop();
        }
        val = sec.top();
        sec.pop();
        while(!sec.empty()){
            res.push(sec.top());
            sec.pop();
        }
        
        return val;
    }
    
    int peek() {
        while(!res.empty()){
            sec.push(res.top());
            res.pop();
        }
        int val = sec.top();
        while(!sec.empty()){
            res.push(sec.top());
            sec.pop();
        }
        return val;
        
        
        
    }
    
    bool empty() {
        return res.empty();
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