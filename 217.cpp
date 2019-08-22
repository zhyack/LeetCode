class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for (auto k:nums)
            if (s.find(k)!=s.end()) return true;
            else s.insert(k);
        return false;
    }
};