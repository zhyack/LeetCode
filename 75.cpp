class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int l=0, r=n-1;
        for (int i = 0;i < n;i++){
            while (nums[i]==0 && l<i || nums[i]==2 && r>i)
                if (nums[i]==0) swap(nums[i], nums[l++]);
                else swap(nums[i], nums[r--]);
            if (nums[i]==2) break;
        }
    }
};