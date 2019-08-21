class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> m;
        int n1 = s.length(), n2 = t.length();
        if (n1!=n2) return false;
        for (int i = 0;i < n1;i++){
            if (m.find(s[i])!=m.end() && m[s[i]]!=t[i]) return false;
            m[s[i]]=t[i];
        }
        m.clear();
        for (int i = 0;i < n1;i++){
            if (m.find(t[i])!=m.end() && m[t[i]]!=s[i]) return false;
            m[t[i]]=s[i];
        }
        return true;
    }
};