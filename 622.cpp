class MyCircularQueue {
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    vector<int> q;
    int l, r, n;
    bool isfull;
    MyCircularQueue(int k) {
        q = vector<int>(k);
        l = 0, r = 0, n = k;
        isfull=false;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if (this->isFull()) return false;
        q[r++]=value;
        if (r>=n) r%=n;
        if (r==l) isfull=true;
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if (this->isEmpty()) return false;
        l++;
        if (l>=n) l%=n;
        isfull=false;
        return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if (this->isEmpty()) return -1;
        return q[l];
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if (this->isEmpty()) return -1;
        return q[(r+n-1)%n];
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return (l==r && !isfull);
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return isfull;
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