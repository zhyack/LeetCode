bool dfs(int d, int dl, char st, char c, unordered_map<char, unordered_map<char, int>> &m, unordered_set<char> &s, int &ret){
    //cout << d << " " << st << " " << c << endl;
    if (c==st && d>0){
        ret += d-1;
        return true;
    }
    if (d>=dl) return false;
    if (m[c][st]){
        dfs(d+1, dl, st, st, m, s, ret);
        m[c][st]--;
        return true;
    }
    for (auto t:m[c]){
        if (s.find(t.first)!=s.end()) continue;
        if (m[c][t.first]){
            s.insert(t.first);
            bool b = dfs(d+1, dl, st, t.first, m, s, ret);
            s.erase(t.first);
            if (b){
                m[c][t.first]--;
                return true;
            }
        }
    }

    return false;
}
class Solution {
public:
    int kSimilarity(string A, string B) {
        int n = A.size();
        unordered_map<char, unordered_map<char, int>> m;
        for (int i = 0;i < n; i++){
            if (A[i]!=B[i]){
                if (m.find(B[i])==m.end()) m[B[i]]=unordered_map<char, int>();
                if (m[B[i]].find(A[i])==m[B[i]].end()) m[B[i]][A[i]]=0;
                m[B[i]][A[i]]++;
            }
        }
        int ret = 0;
        unordered_set<char> s;
        for (int i = 0;i <= 7; i++){
            for(char c='f'; c>='a'; c--){ 
                while(dfs(0, i, c, c, m, s, ret));
            }
        }
        return ret;
    }
};