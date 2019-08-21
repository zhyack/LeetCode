class Vector2D {
public:
    vector<vector<int>> saved_v;
    vector<vector<int>>::iterator it0;
    vector<int>::iterator it1;
    Vector2D(vector<vector<int>>& v) {
        saved_v = v;
        it0 = saved_v.begin();
        if (it0!=saved_v.end()) it1 = it0->begin();
        while(it0!=saved_v.end() && it1 == it0->end()){
            it0++;
            if (it0!=saved_v.end()) it1 = it0->begin();
        }
    }
    
    int next() {
        int ret = *it1;
        it1++;
        while(it0!=saved_v.end() && it1 == it0->end()){
            it0++;
            if (it0!=saved_v.end()) it1 = it0->begin();
        }
        return ret;
    }
    
    bool hasNext() {
        if (it0==saved_v.end()) return false;
        return true;
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(v);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */