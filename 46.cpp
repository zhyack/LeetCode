void dfs(int d, int n, unordered_set<int> s, vector<int> p, vector<vector<int>>& r){
    if (d==n){
        r.push_back(p);
        return;
    }
    unordered_set<int> t=s;
    for (auto a:t){
        p.push_back(a);
        s.erase(a);
        dfs(d+1, n, s, p, r);
        p.pop_back();
        s.insert(a);
    }
}

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret;
        vector<int> p(0);
        unordered_set<int> s;
        for (auto a:nums) s.insert(a);
        dfs(0, nums.size(), s, p, ret);
        return ret;
    }
};