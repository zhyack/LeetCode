struct Node{
    int x, y;
    Node(int xx, int yy){
        x = xx;
        y = yy;
    }
};
bool operator <(const Node &A, const Node &B){
    return A.x<B.x || A.x==B.x && A.y<B.y;
}
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        if (n==0) return 0;
        vector<Node> v;
        for (auto e:envelopes) v.push_back(Node(e[0], e[1]));
        sort(v.begin(), v.end());
        vector<int> dp, tdp(n+1,1e9+7);
        tdp[0] = -1e9+7;
        int ret = 0;
        for (int i =0;i < n;i++){
            if (i==0 || v[i].x!=v[i-1].x)
                dp = tdp;
            int p = lower_bound(dp.begin(), dp.begin()+ret+1, v[i].y)-dp.begin();
            if (dp[p]>v[i].y) tdp[p]=min(tdp[p], v[i].y), ret=max(ret,p);
        }
        return ret;
    }
};