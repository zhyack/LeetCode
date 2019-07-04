class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if (n<2) return;
        int p=2, m=nums[n-1], mp=1;
        while(p<=n && nums[n-p]>=m){
            if (nums[n-p]>m){
                mp = p;
                m = nums[n-p];
            }
            p++;
        }
        if (p==n+1) sort(nums.begin(), nums.end());
        else{
            sort(nums.end()-p+1, nums.end());
            for (int i = p-1; i>=1;i--)
                if (nums[n-i]>nums[n-p]){
                    swap(nums[n-p], nums[n-i]);
                    break;
                }
        }
    }
};