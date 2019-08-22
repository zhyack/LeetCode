class Solution {
public:
    string baseNeg2(int N) {
        if (N==0) return "0";
        string ret="";
        bool odd = false;
        while(N){
            if (N%2==1 && odd) ret+='1', N=(N+1)/2;
            else if (N%2==1) ret+='1', N/=2;
            else ret+='0', N/=2;
            odd = not odd;
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};