int dfs(int n, unordered_map<int,int> &m){
    if (m.find(n)!=m.end()) return m[n];
    if (n&1) m[n]=n-dfs(n/2,m)*2-2;
    else m[n]=n-dfs(n/2,m)*2-1;
    //cout << n << ": " << m[n] << endl;
    return m[n];
}
class Solution {
public:
    int lastRemaining(int n) {
        unordered_map<int, int> m;
        m[1]=0;
        return dfs(n, m)+1;
    }
};
