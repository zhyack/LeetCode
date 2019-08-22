class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        int ret = 0;
        for (int i = 0;i < n; i++){
            dp[i] = nums[i];
            if (i>1) dp[i]+=dp[i-2];
            if (i>2) dp[i] = max(dp[i], dp[i-3]+nums[i]);
            ret = max(ret, dp[i]);
        }
        return ret;
    }
};