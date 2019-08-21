class ExamRoom {
public:
    map<int, set<int>> m;
    set<int> s;
    int n;
    ExamRoom(int N) {
        m.clear();
        m[N].insert(0);
        s.clear();
        n = N;
    }
    
    int seat() {
        auto it = m.rbegin();
        int ret = *(it->second.begin());
        it->second.erase(ret);
        if (it->second.size()==0) m.erase(it->first);
        s.insert(ret);
        auto lb = s.lower_bound(ret);
        if (lb!=s.begin()){
            lb--;
            int d = (ret-*lb)/2;
            int ind = *lb+d;
            m[d].insert(ind);
            lb++;
        }
        else if (ret>0){
            m[ret].insert(0);
        }
        lb++;
        if (lb!=s.end()){
            int d = (*lb-ret)/2;
            int ind = ret+d;
            m[d].insert(ind);
        }
        else if (ret<n-1)
            m[n-1-ret].insert(n-1);
        // for (auto k:s) cout << k << ", ";
        // cout << endl;
        // for (auto k:m) cout << k.first << ", ";
        // cout << endl;
        return ret;
    }
    
    void leave(int p) {
        auto lb = s.lower_bound(p);
        int ll=-1, rr=n;
        if (lb!=s.begin()){
            lb--;
            int d = (p-*lb)/2;
            int ind = *lb+d;
            m[d].erase(ind);
            if (m[d].size()==0) m.erase(d);
            ll=*lb;
            lb++;
        }
        else if (*lb>0) m[*lb].erase(0);
        lb++;
        if (lb!=s.end()){
            int d = (*lb-p)/2;
            int ind = p+d;
            m[d].erase(ind);
            if (m[d].size()==0) m.erase(d);
            rr=*lb;
        }
        else{
            lb--;
            if (*lb<n-1) m[n-1-*lb].erase(n-1);
        }
        if (ll==-1 && rr==n) m[n].insert(0);
        else if (ll==-1) m[rr].insert(0);
        else if (rr==n) m[n-1-ll].insert(n-1);
        else m[(rr-ll)/2].insert(ll+(rr-ll)/2);
        s.erase(p);
        // for (auto k:s) cout << k << ", ";
        // cout << endl;
        // for (auto k:m) cout << k.first << ", ";
        // cout << endl;
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(N);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */