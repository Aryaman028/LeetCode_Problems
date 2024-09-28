class MyCircularDeque {
public:
    int size;
    int rear;
    deque<int>d;
    MyCircularDeque(int k) {
        size=k;
        rear=0;
    }
    
    bool insertFront(int value) {
        if(size==rear)return false;
        rear++;
        d.push_front(value);
        return true;
        
    }
    
    bool insertLast(int value) {
        if(size==rear)return false;
        d.push_back(value);
        rear++;
        return true;
    }
    
    bool deleteFront() {
        if(d.empty())return false;
        rear--;
        d.pop_front();
        return true;
    }
    
    bool deleteLast() {
        if(d.empty())return false;
        rear--;
        d.pop_back();
        return true;
    }
    
    int getFront() {
        if(d.empty())return -1;
        return d.front();
    }
    
    int getRear() {
        if(d.empty())return -1;
        return d.back();
    }
    
    bool isEmpty() {
        return d.empty();
    }
    
    bool isFull() {
        return rear==size;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */