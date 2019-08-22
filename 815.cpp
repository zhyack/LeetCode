class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        if (S==T) return 0;
        unordered_map<int, unordered_set<int>> edges;
        for (int i = 0;i < routes.size();i++)
            for (auto a:routes[i]){
                edges[a].insert(-i-1);
                edges[-i-1].insert(a);
            }
        unordered_map<int, int> ans;
        queue<int> q;
        q.push(S);
        ans[S]=0;
        while(!q.empty()){
            int x = q.front();
            q.pop();
            for (auto y:edges[x]){
                if (ans.find(y)==ans.end()){
                    ans[y]=ans[x]+1;
                    if (y==T) return ans[y]/2;
                    q.push(y);
                }
            }
        }
        return -1;
    }
};