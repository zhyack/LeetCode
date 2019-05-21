class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length();
        while(n>0 && s[n-1]==' ') n--;
        if (n==0) return 0;
        int p = n-1;
        while(p>=0 && s[p]!=' ') p--;
        return n-p-1;
    }
};