class Solution {
public:
    bool splitArraySameAverage(vector<int>& A) {
        int n = A.size(), s=0;
        for (auto i:A) s+=i;
        vector<vector<unordered_set<int>>> dp(n+1, vector<unordered_set<int>>(n+1));
        for (int i = 0;i <=n ;i++) dp[i][0].insert(0);
        for (int i = 1;i <= n;i++)
            for (int j = 1;j <= (i+1)/2;j++){
                if (j<i) dp[i][j]=dp[i-1][j];
                for (auto k:dp[i-1][j-1]) dp[i][j].insert(k+A[i-1]);
            }
        bool ret = false;
        for (int i = 1;i <= n/2; i++) ret = ret || (s*i%n==0 && dp[n][i].find(s*i/n)!=dp[n][i].end());
        return ret;
    }
};