void dfs(unordered_map<char, int> &m, int &ret, char last){
    
    for (auto c:m){
        if (c.first==last) continue;
        int num = c.second;
        for (int i = 1;i <= num; i++){
            m[c.first]--;
            ret++;
            dfs(m, ret, c.first);
        }
        m[c.first] = num;
    }
}

class Solution {
public:
    int numTilePossibilities(string tiles) {
        int n = tiles.size();
        if (n==0) return 0;
        unordered_map<char, int> m;
        for (auto c:tiles) m[c]++;
        int ret=0;
        dfs(m, ret, '.');
        return ret;
    }
};