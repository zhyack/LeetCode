class Solution {
public:
    int smallestRangeII(vector<int>& A, int K) {
        int n = A.size();
        if (n==1) return 0;
        sort(A.begin(), A.end());
        int ans = A[n-1]-A[0];
        for (int i = 0;i < n-1;i++)
            ans = min(ans, max(max(A[i]-A[0], A[n-1]-A[i+1]), max(abs(A[i+1]-A[i]-K*2), abs(A[n-1]-A[0]-K*2))));
        return ans;
    }
};