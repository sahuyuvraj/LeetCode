class MedianFinder {
public:
    priority_queue<int>low;
    priority_queue<int,vector<int>,greater<int>>high;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        low.push(num);
        high.push(low.top());low.pop();
        if(low.size()<high.size()){
            low.push(high.top());high.pop();
        }
    }
    
    double findMedian() {
        int n=low.size()+high.size();
        if(n&1)return low.top()/1.0;
        return (low.top()+high.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */