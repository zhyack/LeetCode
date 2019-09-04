int solve(vector<int> &A, vector<int> &B, int x){
    int n = A.size(), cnta=0, cntb=0;
    for (int i = 0;i < n;i++){
        if (A[i]!=x && B[i]!=x) return n+1;
        if (A[i]==x) cnta++;
        if (B[i]==x) cntb++;
    }
    return n-max(cnta, cntb);
}

class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int ret = min(solve(A,B,A[0]), solve(A,B,B[0]));
        if (ret==A.size()+1) return -1;
        else return ret;
    }
};