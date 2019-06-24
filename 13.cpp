class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> m;
        m['I']=1;
        m['V']=5;
        m['X']=10;
        m['L']=50;
        m['C']=100;
        m['D']=500;
        m['M']=1000;
        int n = s.length();
        if (n==0) return 0;
        int ret = 0;
        char hc='I';
        for (int i = n-1;i >= 0;i--){
            if (m[s[i]]<m[hc]) ret -= m[s[i]];
            else ret += m[s[i]], hc=s[i];
        }
        return ret;
    }
};