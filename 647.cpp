class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int ret = 0;
        for (int i = 0;i < n;i++){
            ret++;
            for (int k = 1; k < n; k++){
                if (i-k<0 || i+k>=n) break;
                if (s[i-k]!=s[i+k]) break;
                ret++;
            }
            if (i+1<n && s[i]==s[i+1]){
                ret++;
                for (int k = 1; k < n; k++){
                    if (i-k<0 || i+k+1>=n) break;
                    if (s[i-k]!=s[i+k+1]) break;
                    ret++;
                }
            }
        }
        return ret;
    }
};