class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size(), sum = 0;
        if (n<2) return false;
        for (int k:nums) sum+=k;
        if (sum&1) return false;
        sum/=2;
        vector<bool> dp(sum, false);
        dp[0]=true;
        for (int i:nums)
            for (int j = sum; j>=i; j--) dp[j] = dp[j]||dp[j-i];
        return dp[sum];
    }
};