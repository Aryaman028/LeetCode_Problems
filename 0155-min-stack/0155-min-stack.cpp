class MinStack {
public:
    stack<int> st;
    stack<int> m;
    MinStack() {
        int val;
        
    }
    
    void push(int val) {
        st.push(val);
        if(m.empty() || m.top()>=val){
            m.push(val);
        }
    }
    
    void pop() {
        if(st.top()==m.top()){
            m.pop();
        }
        st.pop();  
    }
    
    int top() {
        return st.top();
        
    }
    
    int getMin() {
        return m.top();
        
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */