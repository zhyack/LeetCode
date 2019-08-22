class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n==0) return 0;
        vector<int> dp(n+1, 1e9+7);
        dp[0]=-1e9+7;
        int ret = 0;
        for (int i = 0;i < n;i++){
            int k = lower_bound(dp.begin(), dp.end(), nums[i])-dp.begin();
            if (nums[i]<dp[k]) dp[k]=nums[i], ret=max(ret, k);
        }
        return ret;
    }
};