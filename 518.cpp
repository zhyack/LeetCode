class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size(), m=amount;
        vector<int> dp(m+1, 0);
        dp[0]=1;
        for (int i = 0;i < n;i++)
            for (int j = coins[i]; j <= m; j++)
                dp[j] += dp[j-coins[i]];
        return dp[m];
    }
};