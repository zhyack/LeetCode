class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        if (n==1) return;
        nth_element(nums.begin(), nums.begin()+(n-1)/2, nums.end());
        int mid = nums[(n-1)/2], cnt=0;
        for (int i = 0;i <= (n-1)/2;i++) if (nums[i]==mid) cnt++;
        nth_element(nums.begin(), nums.begin()+(n-1)/2+1-cnt, nums.begin()+(n-1)/2+1);
        cnt=0;
        for (int i = (n-1)/2+1;i < n;i++) if (nums[i]==mid) cnt++;
        nth_element(nums.begin()+(n-1)/2+1, nums.begin()+(n-1)/2+1+cnt, nums.end());
        vector<int> ret;
        for (int i = 0;i < n;i++){
            if (i&1) ret.push_back(nums[n-1-i/2]);
            else ret.push_back(nums[(n-1)/2-i/2]);
        }
        nums = ret;
    }
};