class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        int n = nums.size();
        if (n<2) return false;
        if (k>=n) k = n-1;
        for (int i = 0;i <= k;i++){
            m[nums[i]]++;
            if (m[nums[i]]==2) return true;
        }
        for (int i = k+1;i<n;i++){
            m[nums[i-k-1]]--;
            m[nums[i]]++;
            if (m[nums[i]]==2) return true;
        }
        return false;
    }
};