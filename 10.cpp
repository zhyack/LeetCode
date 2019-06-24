bool isRegx(string &s, int k1, string &p, int k2, unordered_set<long long> &h){
    int n1 = s.length(), n2 = p.length();
    long long hash = k1;
    hash = hash*n2+k2;
    if (h.find(hash)!=h.end()) return false;
    if (k1==n1 && k2==n2) return true;
    if (k2==n2) return false;
    if (k1==n1){
        if (!(k2<n2-1 && p[k2+1]=='*')) return false;
        else if (isRegx(s, k1, p, k2+2, h)) return true;
        else{
            h.insert(hash);
            return false;
        }
    }
    if (p[k2]!='.' && s[k1]!=p[k2] && !(k2<n2-1 && p[k2+1]=='*')) return false;
    if (k2<n2-1 && p[k2+1]=='*'){
        int cnts = 0, cntp = 0;
        while(k1+cnts<n1 && (p[k2]=='.' || s[k1+cnts]==p[k2])) cnts++;
        for (int k=cnts; k>=0; k--) 
            if (isRegx(s, k1+k, p, k2+2, h)) return true;
        h.insert(hash);
        return false;
    }
    else if (isRegx(s, k1+1, p, k2+1, h)) return true;
    else {
        h.insert(hash);
        return false;
    }
}

class Solution {
public:
    bool isMatch(string s, string p) {
        unordered_set<long long> h;
        return isRegx(s, 0, p, 0, h);
    }
};