class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int m = wordDict.size(), n = s.length();
        vector<bool> dp(n+1, false);
        dp[0]=true;
        for (int i = 1;i <= n;i++){
            for(auto k:wordDict){
                int kn = k.length();
                if (i>=kn && k==s.substr(i-kn, kn)) dp[i]=dp[i] || dp[i-kn];
                if (dp[i]) break;
            }
        }
        return dp[n];
    }
};