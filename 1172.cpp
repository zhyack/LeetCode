class DinnerPlates {
public:
    vector<stack<int>> v;
    int m,n;
    priority_queue<int, vector<int>, greater<int>> q;
    unordered_set<int> inq;
    DinnerPlates(int capacity) {
        m = capacity;
        n = 0;
        while(!q.empty()) q.pop();
        v.clear();
        inq.clear();
    }
    
    void push(int val) {
        while(!q.empty() && inq.find(q.top())==inq.end()) q.pop();
        if (q.empty()){
            if (v.size()<=n)
                v.push_back(stack<int>());
            inq.insert(n);
            q.push(n++);
        }
        int x = q.top();
        //cout << val << ", " << x << ", " << v[x].size() << endl;
        v[x].push(val);
        if (v[x].size()==m) inq.erase(x);
    }
    
    int pop() {
        while(n>0 && v[n-1].empty()) n--;
        if (n==0) return -1;
        if (v[n-1].size()==m && inq.find(n-1)==inq.end()) q.push(n-1), inq.insert(n-1);
        int ret = v[n-1].top();
        v[n-1].pop();
        return ret;
    }
    
    int popAtStack(int index) {
        if (index>=n) return -1;
        if (v[index].empty()) return -1;
        if (v[index].size()==m && inq.find(index)==inq.end()) q.push(index), inq.insert(index);
        int ret = v[index].top();
        v[index].pop();
        return ret;
    }
};

/**
 * Your DinnerPlates object will be instantiated and called as such:
 * DinnerPlates* obj = new DinnerPlates(capacity);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAtStack(index);
 */