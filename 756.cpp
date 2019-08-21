bool dfs(string s, unordered_map<string, unordered_set<char>> m);

bool gatherInfo(int d, string cs, string os, unordered_map<string, unordered_set<char>> m){
    if (d==os.length()-1){
        if (dfs(cs, m)) return true;
        else return false;
    }
    string key = os.substr(d,2);
    if (m.find(key)!=m.end())
        for (char c:m[key])
            if (gatherInfo(d+1, cs+string(1,c), os, m)) return true;
    return false;
}


bool dfs(string s, unordered_map<string, unordered_set<char>> m){
    int n = s.length();
    if (n==1) return true;
    return gatherInfo(0, "", s, m);
}

class Solution {
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_map<string, unordered_set<char>> m;
        for (auto a:allowed) m[a.substr(0, a.length()-1)].insert(a[a.length()-1]);
        return dfs(bottom, m);
    }
};