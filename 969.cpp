class Solution {
public:
    void mirror(vector<int>& A, int p){
        for (int i = 0;i <= p/2;i++) swap(A[i], A[p-i]);
    }
    vector<int> pancakeSort(vector<int>& A) {
        int n = A.size();
        vector<int> ret(0);
        for (int i = n-1;i>0;i--){
            int p=0;
            for (int k = 1;k <= i;k++)
                if (A[k]>A[p]) p=k;
            ret.push_back(p+1);
            mirror(A, p);
            ret.push_back(i+1);
            mirror(A, i);
        }
        return ret;
    }
};