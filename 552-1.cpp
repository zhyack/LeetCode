const int MOD=1e9+7;
class Solution {
public:
    int checkRecord(int n) {
        vector<vector<long long>> dp(2, vector<long long>(3,0));
        vector<vector<long long>> np(2, vector<long long>(3,0));
        dp[0][0]=1;
        dp[0][1]=1;
        dp[0][2]=0;
        dp[1][0]=1;
        dp[1][1]=0;
        dp[1][2]=0;
        for (int i = 1;i <= n;i++){
            np[0][0] = (dp[0][0]+dp[0][1]+dp[0][2])%MOD;
            np[0][1] = dp[0][0];
            np[0][2] = dp[0][1];
            np[1][0] = (dp[1][0]+dp[1][1]+dp[1][2]+dp[0][0]+dp[0][1]+dp[0][2])%MOD;
            np[1][1] = dp[1][0];
            np[1][2] = dp[1][1];
            dp = np;
        }
        return dp[1][0];
    }
};