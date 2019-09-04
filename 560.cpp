class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if (n==0) return 0;
        unordered_map<int,int> m;
        m[0] = 1;
        int sum = 0, ret = 0;
        for (int i:nums){
            sum += i;
            ret += m[sum-k];
            m[sum]++;
        }
        return ret;
    }
};