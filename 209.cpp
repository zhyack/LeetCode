class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        int l=0, r=0, sum=0, ret=n+1;
        while(l<n){
            if (r) sum-=nums[l++];
            while(r<n && sum<s) sum+=nums[r++];
            if (sum>=s) ret = min(ret, r-l);
        }
        if (ret==n+1) ret=0;
        return ret;
    }
};