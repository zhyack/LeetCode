void dfs(int d, vector<int>& nums, vector<int> p, vector<vector<int>>& r){
    if (d==nums.size()) return;
    dfs(d+1, nums, p, r);
    p.push_back(nums[d]);
    r.push_back(p);
    dfs(d+1, nums, p, r);
}

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> p(0);
        ret.push_back(p);
        dfs(0, nums, p, ret);
        return ret;
    }
};