class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
        int n = A.size();
        int ldps=1, ldpn=0, dps=n+1, dpn=n+1;
        for (int i = 1;i < n; i++){
            if (ldpn!=-1){
                if (A[i]>B[i-1] && B[i]>A[i-1]) dps=min(dps, ldpn+1);
                if (A[i]>A[i-1] && B[i]>B[i-1]) dpn=min(dpn, ldpn);
            }
            if (ldps!=0){
                if (A[i]>B[i-1] && B[i]>A[i-1]) dpn=min(dpn, ldps);
                if (A[i]>A[i-1] && B[i]>B[i-1]) dps=min(dps, ldps+1);
            }
            ldps=dps;
            ldpn=dpn;
            dps=dpn=n+1;
        }
        int ret = n+1;
        if (ldps<=n) ret = min(ret, ldps);
        if (ldpn<=n) ret = min(ret, ldpn);
        return ret;
    }
};