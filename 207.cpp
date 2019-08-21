bool dfs(int x, vector<bool> &v, vector<bool> &g, vector<vector<int>> &e){
    if (v[x]) return true;
    v[x]=true;
    g[x]=true;
    for (int y:e[x])
        if (dfs(y, v, g, e)) return true;
    v[x]=false;
    return false;
}

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        if (n==0) return true;
        vector<vector<int>> edges(numCourses);
        for (auto e:prerequisites) edges[e[0]].push_back(e[1]);
        vector<bool> visited(numCourses, false), good(numCourses, false);
        for (int i = 0;i < numCourses;i++)
            if (!good[i] && dfs(i, visited, good, edges)) return false;
        return true;
    }
};