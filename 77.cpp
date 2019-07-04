void dfs(int d, int n, int k, int last_num, vector<int> p, vector<vector<int>> &r){
    if (d==k){
        r.push_back(p);
        return;
    }
    if (last_num>=n) return;
    for (int i = last_num+1; i <= n; i++){
        p.push_back(i);
        dfs(d+1, n, k, i, p, r);
        p.pop_back();
    }
}
    
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ret;
        vector<int> p(0);
        dfs(0, n, k, 0, p, ret);
        return ret;
    }
};