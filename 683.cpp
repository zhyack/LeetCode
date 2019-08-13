class Solution {
public:
    int kEmptySlots(vector<int>& bulbs, int K) {
        set<int> s;
        int n = bulbs.size();
        s.insert(0);
        s.insert(n+1);
        for (int i=0;i < n;i++){
            int x = bulbs[i];
            auto it=s.lower_bound(x);
            //cout << *it << "," << x << endl;
            if (*it<=n && *it-x==K+1) return i+1;
            it--;
            //cout << *it << "," << x << endl;
            if (*it>0 && x-*it==K+1) return i+1;
            s.insert(x);
        }
        return -1;
    }
};