bool dfs(int x, int y, int left, string& p, string& s, unordered_map<char, string>& m, unordered_map<char, int>& l, unordered_set<string> ws){
    if (x==p.length()){
        if (y==s.length()) return true;
        else return false;
    }
    if (m.find(p[x])!=m.end()){
        if (m[p[x]]==s.substr(y,m[p[x]].length()))
            return dfs(x+1, y+m[p[x]].length(), left, p, s, m, l, ws);
        else return false;
    }
    for (int len=1; len<=left/l[p[x]]; len++){
        if (ws.find(s.substr(y, len))!=ws.end()) continue;
        m[p[x]]=s.substr(y, len);
        ws.insert(m[p[x]]);
        if (dfs(x+1, y+len, left-len*l[p[x]], p, s, m , l, ws)) return true;
        ws.erase(m[p[x]]);
        m.erase(p[x]);
    }
    return false;
}

class Solution {
public:
    bool wordPatternMatch(string pattern, string str) {
        if (pattern.size()==0 && str.size()==0) return true;
        if (pattern.size()==0 || str.size()==0) return false;
        unordered_map<char, string> m;
        unordered_map<char, int> left;
        unordered_set<string> ws;
        for (char c:pattern) left[c]++;
        return dfs(0,0,str.length(),pattern, str, m, left, ws);
    }
};