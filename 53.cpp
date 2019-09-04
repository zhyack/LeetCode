class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if (n==0) return 0;
        int ret = nums[0];
        int pre_min = 0, sum = 0;
        for (auto i:nums){
            sum+=i;
            ret = max(ret, sum-pre_min);
            pre_min = min(pre_min, sum);
        }
        return ret;
    }
};