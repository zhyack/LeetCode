class SnapshotArray {
public:
    vector<vector<pair<int,int>>> a;
    int now;
    SnapshotArray(int length) {
        a = vector<vector<pair<int,int>>>(length, vector<pair<int,int>>(1, make_pair(-1, 0)));
        now = -1;
    }
    
    void set(int index, int val) {
        int n = a[index].size();
        if (val!=a[index][n-1].second){
            if (now == a[index][n-1].first) a[index][n-1].second=val;
            else a[index].push_back(make_pair(now, val));
        }
    }
    
    int snap() {
        now++;
        return now;
    }
    
    int get(int index, int snap_id) {
        int l = 0, r = a[index].size()-1;
        while(l<r){
            int m = (l+r+1)/2;
            if (a[index][m].first>=snap_id) r=m-1;
            else l=m;
        }
        return a[index][l].second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */