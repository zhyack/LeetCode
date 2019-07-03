class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        int n = A.size();
        unordered_map<int, queue<int>> cnt;
        int l = 0, r = 0, cc=0, tp=0, np=n, ret=0;
        while(l<n){
            if (r){
                cnt[A[l]].pop();
                if (!cnt[A[l]].empty()) tp = max(tp, cnt[A[l]].front());
                else{
                    tp=np;
                    cc--;
                    np++;
                }
                l++;
            }
            while(r<n && cc<=K){
                if (cnt[A[r]].empty()){
                    cc++;
                    if (cc<=K) tp=r;
                    if (cc>K) np=r;
                }
                cnt[A[r]].push(r);
                r++;
                if (r==n && cc<=K) np=n;
            }
            if (cc>=K) ret += np-tp;
        }
        return ret;
    }
};