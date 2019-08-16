class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n==0) return 0;
        vector<int> dp(n, 0);
        map<int, int> m;
        for (int i = 0;i < n;i++){
            m[prices[i]]=i;
            if (i) dp[i]=dp[i-1];
            for (auto it:m){
                if (it.first==prices[i]) break;
                dp[i] = max(dp[i], dp[it.second]+prices[i]-it.first);
            }
        }
        return dp[n-1];
    }
};