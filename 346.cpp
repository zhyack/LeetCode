class MovingAverage {
public:
    /** Initialize your data structure here. */
    int s, sum;
    queue<int> q;
    MovingAverage(int size) {
        s = size;
        while(!q.empty()) q.pop();
        sum = 0;
    }
    
    double next(int val) {
        q.push(val);
        sum += val;
        while(q.size()>s){
            sum -= q.front();
            q.pop();
        }
        return double(sum)/q.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */