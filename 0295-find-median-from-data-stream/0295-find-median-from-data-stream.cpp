class MedianFinder {
private:
    priority_queue<long> small; // max heap
    priority_queue<long, vector<long>, greater<long>> large; // min heap
    bool even = true;

public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(even){
            large.push(num);
            small.push(large.top());
            large.pop();
        } else {
            small.push(num);
            large.push(small.top());
            small.pop();
        }
        even = !even;
    }
    
    double findMedian() {
        if(even){
            return (small.top() + large.top()) / 2.0;
        } else {
            return small.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */