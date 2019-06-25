const long long MOD=1e9+7;
unordered_set<long long> buildHash(string s, int k){
    int n = s.length();
    unordered_set<long long> m;
    long long h = 0, p=1;
    for (int i = 0;i < min(k,n);i++){
        h = (h*27+s[i]-'a'+1)%MOD;
        p = p*27%MOD;
    }
    m.insert(h);
    if (k>n) return m;
    for (int i = k;i < n; i++){
        h = (h*27+s[i]-'a'+1-(s[i-k]-'a'+1)*p%MOD+MOD)%MOD;
        m.insert(h);
    }
    return m;
}
class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        int n = A.length(), m = B.length();
        int l = (m+n-1)/n, r = (m-1)/n+2;
        unordered_set<long long> sa, sb, ssa;
        sa=buildHash(A+A, min(m,n)), sb=buildHash(B, min(m,n)), ssa=buildHash(A,min(m,n));
        for (unordered_set<long long>::iterator it=sb.begin(); it!=sb.end();it++)
            if (sa.find(*it)==sa.end()) return -1;
        if (m<=n)
            if (ssa.find(*sb.begin())!=ssa.end()) return 1;
            else return 2;
        else if (B.substr(0, min(m,n)) == A.substr(0, min(m,n)) || B.substr(m-min(m,n), min(m,n)) == A.substr(n-min(m,n), min(m,n))) return l;
        else{
            long long h = 0, p=1, g=0;
            for (int i = 0;i < n;i++){
                h = (h*27+A[i]-'a'+1)%MOD;
                g = (g*27+B[i]-'a'+1)%MOD;
                p = p*27%MOD;
            }
            for (int i = 0;i < n; i++){
                if (g==h) return 1+(m-(n-i)+n-1)/n;
                h = (h*27+A[i]-'a'+1-(A[i]-'a'+1)*p%MOD+MOD)%MOD;
            }
        }
        return r;
    }
};