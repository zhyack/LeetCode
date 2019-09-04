class Solution {
public:
    int shortestWay(string source, string target) {
        if (target.length()==0) return 0;
        unordered_map<char, vector<int>> m;
        for (int i = 0;i < source.length(); i++) m[source[i]].push_back(i);
        int ret = 1, p = 0;
        for (char c:target){
            if (m.find(c)==m.end()) return -1;
            if (p>*(m[c].rbegin())){
                ret++;
                p=0;
            }
            p = m[c][lower_bound(m[c].begin(), m[c].end(), p)-m[c].begin()];
            p++;
        }
        return ret;
    }
};