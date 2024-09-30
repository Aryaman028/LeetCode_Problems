class CustomStack {
public:
    int maxSize;
    int size;
    stack<int>s;
    stack<int>sec;
    CustomStack(int maxSize) {
        this->maxSize=maxSize;
        size = 0;
    }
    
    void push(int x) {
        if(maxSize>size){
            s.push(x);
            size++;
        }else return;
    }
    
    int pop() {
        if(s.empty())return -1;
        int val = s.top();
        s.pop();
        size--;
        return val;
    }
    
    void increment(int k, int val) {
        if(size<k){
            while(!s.empty()){
                sec.push(s.top()+val);
                s.pop();
            }
            while(!sec.empty()){
                s.push(sec.top());
                sec.pop();
            }
        }else{
            int c=size-k;
            int i=0;
            while(!s.empty() && i!=c){
                sec.push(s.top());
                s.pop();
                i++;
            }
            while(!s.empty()){
                sec.push(s.top()+val);
                s.pop();
            }
            while(!sec.empty()){
                s.push(sec.top());
                sec.pop();
            }
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */