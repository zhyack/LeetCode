int calc(int x, int y){
    if (x>y) return 1;
    else if (x==y) return 0;
    else return -1;
}
class Solution {
public:
    int maxTurbulenceSize(vector<int>& A) {
        int n = A.size();
        if (n<2) return n;
        int b = calc(A[0],A[1]);
        int ret=abs(b)+1, cnt=abs(b)+1;
        for (int i=2;i < n;i++){
            int c = calc(A[i-1],A[i]);
            if (c && b!=c) cnt++;
            else if (c) cnt=2;
            else cnt=1;
            b = c;
            ret = max(ret, cnt);
        }
        return ret;
    }
};