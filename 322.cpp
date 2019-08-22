class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount==0) return 0;
        vector<int> dp(amount+1, amount+1);
        dp[0] = 0;
        for (int i:coins){
            if (i<=0) continue;
            for (int j = i;j <= amount;j++) dp[j]=min(dp[j], dp[j-i]+1);
        }
        if (dp[amount]==amount+1) return -1;
        return dp[amount];
    }
};