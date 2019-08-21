class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> edges(n);
        vector<int> d(n,0);
        for (auto e:prerequisites) edges[e[1]].push_back(e[0]), d[e[0]]++;
        queue<int> q;
        vector<int> ret;
        for (int i = 0;i < n;i++) if (d[i]==0) q.push(i);
        while(!q.empty()){
            int x = q.front();
            q.pop();
            ret.push_back(x);
            for (int y:edges[x]){
                d[y]--;
                if (d[y]==0) q.push(y);
            }
        }
        if (ret.size()==n) return ret;
        else return vector<int>();
        
    }
};