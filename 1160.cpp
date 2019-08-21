class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char, int> m,t;
        for (auto c:chars) m[c]++;
        int ret = 0;
        for (auto w:words){
            bool ok = true;
            t.clear();
            for (auto c:w)
                if (m.find(c)!=m.end())
                   t[c]++;
                else{
                    ok = false;
                    break;
                }
            if (!ok) continue;
            for (auto it:m)
                if (it.second<t[it.first]){
                    ok = false;
                    break;
                }
            if (ok) ret += w.length();
        }
        return ret;
    }
};