void dfs(int x, unordered_map<int, unordered_set<int>> &e, vector<int> &r){
    r.push_back(x);
    if (e.find(x)!=e.end())
        for (int k:e[x]) dfs(k, e, r);
}

class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        unordered_map<int, unordered_set<int>> edge;
        int n = pid.size();
        for (int i = 0;i < n; i++) edge[ppid[i]].insert(pid[i]);
        vector<int> ret;
        dfs(kill, edge, ret);
        return ret;
    }
};