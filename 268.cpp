class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size(), s=0;
        for (auto i:nums) s+=i;
        return n*(n+1)/2-s;
    }
};