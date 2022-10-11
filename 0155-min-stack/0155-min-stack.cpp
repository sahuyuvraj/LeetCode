class MinStack {
public:
    stack<long>s;
    long minEle;
    MinStack() {
        
    }
    
    void push(int val) {
        long v=val;
        if(s.empty()){
            s.push(v);
            minEle=v;
        }else if(v<minEle){
            s.push(2*v-minEle);
            minEle=v;
        }else s.push(v);
    }
    
    void pop() {
        if(s.top()<minEle)minEle=2*minEle-s.top();
        s.pop();
    }
    
    int top() {
        return s.top()<minEle?minEle:s.top();
    }
    
    int getMin() {
        return minEle;
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