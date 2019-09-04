struct Node{
    int val, id, cnt;
};


void msort(vector<Node> &a, int l, int r){
    if (l==r) return;
    int m = (l+r)/2;
    msort(a, l, m);
    msort(a, m+1, r);
    vector<Node> res;
    int p1 = l, p2 = m+1;
    while(p1<=m && p2<=r){
        if (a[p1].val<=a[p2].val){
            a[p1].cnt+=p2-m-1;
            res.push_back(a[p1++]);
        }
        else res.push_back(a[p2++]);
    }
    while(p1<=m){
        a[p1].cnt+=r-m;
        res.push_back(a[p1++]);
    }
    while(p2<=r) res.push_back(a[p2++]);
    for (int i = l; i<=r ;i++) a[i]=res[i-l];
}

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        if (n==0) return vector<int>();
        vector<int> ret(n);
        vector<Node> a(n);
        for (int i = 0;i < n;i++){
            a[i].val = nums[i];
            a[i].id = i;
            a[i].cnt = 0;
        }
        msort(a, 0, n-1);
        for (auto i:a)
            ret[i.id]=i.cnt;
        return ret;
    }
};