class Solution {
public:
    int myAtoi(string str) {
        int n = str.length(), p = 0;
        while(p<n && str[p]==' ') p++;
        if (p==n) return 0;
        bool neg=false;
        if (str[p]=='-') neg=true, p++;
        else if (str[p]=='+') neg=false, p++;
        long long ret = 0;
        while(p<n && str[p]>='0' && str[p]<='9'){
            ret = ret*10+(str[p]-'0')*(neg?-1:1);
            if (int(ret)!=ret){
                if(ret<0) return -2147483648;
                else return 2147483647;
            }
            p++;
        }
        return ret;
    }
};