void dfs(int d, vector<int>& nums, vector<int> p, vector<vector<int>>& r){
    if (d==nums.size()) return;
    int cnt=0;
    while(d+cnt<nums.size() && nums[d+cnt]==nums[d]) cnt++;
    dfs(d+cnt, nums, p, r);
    for (int i = 0;i < cnt;i++){
        p.push_back(nums[d]);
        r.push_back(p);
        dfs(d+cnt, nums, p, r);
    }
}

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret;
        vector<int> p(0);
        ret.push_back(p);
        dfs(0, nums, p, ret);
        return ret;
    }
};