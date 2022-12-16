class MyQueue {
public:
    stack<int> pri, sec;
    MyQueue() {
        
    }
    
    void push(int x) {
        pri.push(x);
    }
    
    int pop() {
        if(sec.empty()){
            while(!pri.empty()){
                sec.push(pri.top());
                pri.pop();
            }
        }
        int front = sec.top();
        sec.pop();
        return front;
    }
    
    int peek() {
        if(sec.empty()){
            while(!pri.empty()){
                sec.push(pri.top());
                pri.pop();
            }
        }
        return sec.top();
    }
    
    bool empty() {
        return pri.empty() && sec.empty();
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