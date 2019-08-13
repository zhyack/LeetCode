struct Node{
    int a,b,v;
};
bool operator < (const Node& A, const Node& B){
    return (A.v<B.v || A.v==B.v && (A.a<B.a || A.a==B.a && A.b<B.b));
}
class Solution {
public:
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        int nw = workers.size(), nb = bikes.size();
        vector<Node> v(nw*nb);
        for (int i = 0;i < nw;i++)
            for (int j = 0;j < nb;j++){
                int p = i*nb+j;
                v[p].a = i;
                v[p].b = j;
                v[p].v = abs(workers[i][0]-bikes[j][0])+abs(workers[i][1]-bikes[j][1]);
            }                
        sort(v.begin(), v.end());
        vector<int> ans(nw, -1), used(nb, -1);
        for (auto x:v)
            if (ans[x.a]==-1 && used[x.b]==-1){
                ans[x.a]=x.b;
                used[x.b]=x.a;
            }
        return ans;
    }
};