const int MOD=1e9+7;
class Solution {
public:
    int knightDialer(int N) {
        vector<int> dp(10, 1);
        for (int i = 0;i < N-1; i++){
            vector<int> np(10, 0);
            np[0] = (dp[4]+dp[6])%MOD;
            np[1] = (dp[6]+dp[8])%MOD;
            np[2] = (dp[7]+dp[9])%MOD;
            np[3] = (dp[4]+dp[8])%MOD;
            np[4] = ((dp[3]+dp[9])%MOD+dp[0])%MOD;
            np[5] = 0;
            np[6] = ((dp[1]+dp[7])%MOD+dp[0])%MOD;
            np[7] = (dp[2]+dp[6])%MOD;
            np[8] = (dp[1]+dp[3])%MOD;
            np[9] = (dp[2]+dp[4])%MOD;
            dp=np;
        }
        int ret = 0;
        for (int i = 0;i < 10;i++) ret = (ret+dp[i])%MOD;
        return ret;
    }
};