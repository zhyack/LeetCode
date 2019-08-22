class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int, vector<int>, greater<int>> minq;
    priority_queue<int, vector<int>, less<int>> maxq;
    MedianFinder() {
        while(!minq.empty()) minq.pop();
        while(!maxq.empty()) maxq.pop();
    }
    
    void addNum(int num) {
        maxq.push(num);
        if (minq.size()>0 && maxq.top()>minq.top()){
            minq.push(maxq.top());
            maxq.push(minq.top());
            minq.pop();
            maxq.pop();
        }
        if (maxq.size()-minq.size()==2){
            minq.push(maxq.top());
            maxq.pop();
        }
    }
    
    double findMedian() {
        if (maxq.size()==minq.size()) return (double(maxq.top())+double(minq.top()))/2.0;
        else return maxq.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */