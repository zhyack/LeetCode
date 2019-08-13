class Solution {
public:
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
        queue<pair<int,int>> q;
        vector<unordered_set<int>> ne(n);
        for (auto e:edges) ne[e[0]].insert(e[1]);
        q.push(make_pair(source, 0));
        vector<int> depth(n,0);
        int path_cnt=0;
        while(!q.empty()){
            auto item = q.front();
            q.pop();
            int x = item.first, d = item.second;
            if (d>=n) return false;
            if (x==destination)
                path_cnt++;
            else if (ne[x].size()==0) return false;
            if (d<n*2)
                for (int y:ne[x]) 
                    if (depth[y]<d+1)
                        q.push(make_pair(y, d+1)), depth[y]=d+1;
        }
        return path_cnt>0;
    }
};