class Solution {
public:
    void deal(string s, long long &a, long long &b, long long &c, long long &d, long long &e){
        a=b=d=0, c = 1, e = 0;
        int p = 0;
        for (int i = 0;i < s.length();i++){
            if (s[i]=='.' || s[i]=='(' || s[i]==')'){
                p++;
                continue;
            }
            if (p==0) a=a*10+int(s[i])-int('0');
            else if (p==1){
                c*=10;
                b=b*10+int(s[i])-int('0');
            }
            else{
                e=e*10+9;
                d=d*10+int(s[i])-int('0');
            }
        }
        if (e==0) e=1;
        e *= c;
        
    }
    bool isRationalEqual(string S, string T) {
        long long a1,a2, b1,b2, c1,c2, d1,d2, e1,e2;
        deal(S, a1, b1, c1, d1, e1);
        deal(T, a2, b2, c2, d2, e2);
        return (a1*e1+e1/c1*b1+d1)*e2==(a2*e2+e2/c2*b2+d2)*e1;
    }
};