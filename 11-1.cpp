struct Node{
    int x, h;
};
bool operator < (const Node &A, const Node &B){
    return A.h<B.h;
}
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        vector<Node> a(n);
        for (int i = 0;i < n;i++) a[i].x=i, a[i].h=height[i];
        sort(a.begin(), a.end());
        int ml = a[n-1].x, mr = a[n-1].x, ret=0;
        for (int i = n-2; i >= 0; i--){
            ml = min(ml, a[i].x);
            mr = max(mr, a[i].x);
            if (ml==a[i].x || mr==a[i].x) ret = max(ret, (mr-ml)*a[i].h);
        }
        return ret;
    }
};