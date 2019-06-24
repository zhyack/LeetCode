void dfs(long long x, long long &r){
    if (x==0) return;
    r = r*10+x%10;
    dfs(x/10, r);
}

class Solution {
public:
    int reverse(int x) {
        bool neg=(x<0);
        long long ret = 0;
        dfs(neg?-(long long)(x):x, ret);
        if (int(ret)!=ret) return 0;
        return neg?-ret:ret;
    }
};