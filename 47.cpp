void dfs(int d, int n, unordered_map<int,int> m, vector<int> p, vector<vector<int>>& r, int last_num){
    if (d==n){
        r.push_back(p);
        return;
    }
    unordered_map<int, int> t=m;
    for (auto a:t){
        if (a.first==last_num) continue;
        for (int k = 1;k <= a.second; k++){
            p.push_back(a.first);
            m[a.first]--;
            if (m[a.first]==0) m.erase(a.first);
            dfs(d+k, n, m, p, r, a.first);
        }
        for (int k = 1;k <= a.second; k++) p.pop_back();
        m[a.first]=a.second;
    }
}
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        unordered_map<int, int> m;
        vector<vector<int>> ret;
        vector<int> p(0);
        for (auto a:nums){
            if (m.find(a)==m.end()) m[a]=0;
            m[a]++;
        }
        dfs(0, nums.size(), m, p, ret, -1e9-7);
        return ret;
    }
};