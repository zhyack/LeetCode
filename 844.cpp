void run(string &s, vector<char> &a, int &n){
    for (char c:s){
        if (c=='#' && n>0) n--;
        else if (c!='#') a[n++]=c;
    }
}

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        vector<char> a(S.length()),b(T.length());
        int cnta=0, cntb=0;
        run(S,a,cnta);
        run(T,b,cntb);
        if (cnta!=cntb) return false;
        for (int i = 0;i < cnta; i++)
            if (a[i]!=b[i]) return false;
        return true;
        
    }
};