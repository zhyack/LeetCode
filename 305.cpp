int top(int x, unordered_map<int, int>& f){
    if (f[x]!=x) f[x]=top(f[x], f);
    return f[x];
}

const int dirs[4][2]={0,1,0,-1,1,0,-1,0};

class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        unordered_map<int, int> f;
        int cnt = 0;
        vector<int> ret;
        for (auto p:positions){
            int x = p[0], y = p[1];
            if (f.find(x*n+y)!=f.end()){
                ret.push_back(cnt);
                continue;
            }
            f[x*n+y]=x*n+y;
            cnt++;
            for (int d = 0;d < 4;d++){
                int nx = x+dirs[d][0], ny=y+dirs[d][1];
                if (nx>=0 && nx<m && ny>=0 && ny<n && f.find(nx*n+ny)!=f.end()){
                    int fx = top(x*n+y, f), fy = top(nx*n+ny, f);
                    if (fx!=fy) f[fx]=fy, cnt--;
                }
            }
            ret.push_back(cnt);
        }
        return ret;
    }
};