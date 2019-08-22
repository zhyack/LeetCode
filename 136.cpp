class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ret = 0;
        for (int k:nums) ret^=k;
        return ret;
    }
};