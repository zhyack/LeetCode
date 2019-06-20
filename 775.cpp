class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
        int n = A.size();
        if (n<=2) return true;
        vector<int> mina(n,5010), maxa(n,-1);
        maxa[0]=A[0];
        for (int i = 1; i < n;i++) maxa[i] = max(maxa[i-1], A[i]);
        mina[n-1]=A[n-1];
        for (int i = n-2; i >= 0;i--) mina[i] = min(mina[i+1], A[i]);
        for (int i = 0; i<n;i++)
            if (i<n-2 && A[i]>mina[i+2] || i>=2 && A[i]<maxa[i-2]) return false;
        return true;
    }
};