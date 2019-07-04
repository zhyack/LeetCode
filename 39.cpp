void dfs(int n, int st, int sum, vector<int>& candidates, int target, vector<int> p, vector<vector<int>> &r){
    if (sum==target){
        r.push_back(p);
        return;
    }
    for (int i = st; i < n; i++){
        for (int k = 1; k <= (target-sum)/candidates[i]; k++){
            p.push_back(candidates[i]);
            dfs(n, i+1, sum+k*candidates[i], candidates, target, p, r);
        }
        for (int k = 1; k <= (target-sum)/candidates[i]; k++) p.pop_back();
    }
}

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ret;
        vector<int> p(0);
        int n = candidates.size();
        dfs(n, 0, 0, candidates, target, p, ret);
        return ret;
    }
};