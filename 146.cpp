class LRUCache {
public:
    queue<int> q;
    unordered_map<int, int> m, c;
    int cap;
    LRUCache(int capacity) {
        while(!q.empty()) q.pop();
        m.clear();
        c.clear();
        cap = capacity;
    }
    
    int get(int key) {
        if (m.find(key)==m.end()) return -1;
        else{
            q.push(key);
            c[key]++;
            return m[key];
        }
    }
    
    void put(int key, int value) {
        q.push(key);
        m[key]=value;
        c[key]++;
        while(m.size()>cap){
            c[q.front()]--;
            if (c[q.front()]==0){
                c.erase(q.front());
                m.erase(q.front());
            }
            q.pop();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */