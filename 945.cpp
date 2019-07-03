class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        sort(A.begin(), A.end());
        int n = A.size();
        int ret = 0;
        for(int i = 1;i< n;i++) if (A[i]<=A[i-1]){
            ret += A[i-1]+1-A[i];
            A[i] = A[i-1]+1;
        }
        return ret;
    }
};