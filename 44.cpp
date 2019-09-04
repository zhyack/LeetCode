class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.length(), m = p.length();
        if (n==0 && m==0) return true;
        if (m==0) return false;
        bool full_of_star = true;
        for (auto c:p) if (c!='*'){
            full_of_star = false;
            break;
        }
        if (full_of_star) return true;
        if (n==0) return false;
        vector<vector<bool>> dp(n, vector<bool>(m, false));
        if (p[0]!='*' && p[0]!=s[0] && p[0]!='?') return false;
        dp[0][0]=true;
        for (int i = 1;i < n;i++){
            if (p[0]=='*') dp[i][0]=true;
            else dp[i][0]=false;
        }
        bool already_match = (p[0]==s[0] || p[0]=='?');
        for (int i = 1;i < m;i++){
            dp[0][i]=(dp[0][i-1] && p[i]=='*') || (!already_match &&  (p[i]==s[0] || p[i]=='?'));
            if (p[i]!='*') already_match=true;
        }
        for (int i = 1;i < n;i++){
            for (int j = 1;j < m;j++){
                if (p[j]=='*') dp[i][j] = dp[i-1][j]||dp[i-1][j-1]||dp[i][j-1];
                else if (p[j]=='?') dp[i][j] = dp[i-1][j-1];
                else dp[i][j]=(s[i]==p[j]) && dp[i-1][j-1];
            }
        }
        return dp[n-1][m-1];
    }
};