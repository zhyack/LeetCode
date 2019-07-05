class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0;i < n;i++)
            while(nums[i]-1<n && nums[i]-1>=0 && nums[i]-1!=i && nums[nums[i]-1]-1!=nums[i]-1)
                swap(nums[i], nums[nums[i]-1]);
        for (int i = 0;i < n;i++)
            if (nums[i]-1!=i) return i+1;
        return n+1;
    }
};