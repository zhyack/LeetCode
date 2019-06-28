void findNext(string B,vector<int>& next){
    int m = B.length();
    int j = -1;
    for (int i = 1;i < m;i++){
        while(j>=0 && B[j+1]!=B[i]) j = next[j];
        if (B[j+1] == B[i]) j++;
        next[i] = j;
    }
}

int kmp(string A, string B){
    int n = A.length(), m=B.length();
    vector<int> next(m, -1);
    findNext(B, next);
    int cnt = 0;
    int j = -1;
    for (int i = 0;i < n;i++){
        while(j>=0 && B[j+1]!=A[i]) j = next[j];
        if (B[j+1] == A[i]) j++;
        if (j == m-1) {
            j = next[j];
            return i-m+1;
        }
    }
    return -1;
}
class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.length(), m=needle.length();
        if (n<m) return -1;
        if (m==0) return 0;
        return kmp(haystack, needle);
    }
};