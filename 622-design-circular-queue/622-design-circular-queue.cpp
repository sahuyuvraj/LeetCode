class MyCircularQueue {
    
private:
    vector<int> q; 
    int front = 0, rear = 0; 
    int qSize = 0;  
public:
    MyCircularQueue(int k) {
        q.resize(k+1);  
        qSize = k+1;  
    }
    
    bool enQueue(int value) {
        if (isFull()) return false;
        rear = (rear + 1) % qSize;
        q[rear] = value;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) return false;
        front = (front + 1) % qSize;
        return true;
    }
    
    int Front() {
        if (isEmpty()) return -1;
        return q[(front + 1) % qSize]; 
        
    }
    
    int Rear() {
        if (isEmpty()) return -1;
        return q[rear];  
    }
    
    bool isEmpty() {
        return front == rear; 
    }
    
    bool isFull() {
        return (rear + 1) % qSize == front;  
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */