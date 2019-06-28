void dfs(string s, int l, bool p, int &n, vector<string> &vs){
    int d = s.length();
    if (l>n || l<(d+1)/2) return;
    if (d==n*2){
        vs.push_back(s);
        return;
    }
    string t = s;
    if (!p){
        for (int i = 1;i <= n-l;i++){
            t += '(';
            dfs(t, l+i, true, n, vs);
        }
    }
    if (p){
        for (int i = 1;i <= n-(d-l);i++){
            t += ')';
            dfs(t, l, false, n, vs);
        }
    }
}
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> vs;
        dfs("", 0, false, n, vs);
        return vs;
    }
};