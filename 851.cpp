class Solution {
public:
    int dfs(int x, vector<vector<int>>& rich, vector<int>& quiet, vector<int>& ans){
        if (ans[x]>=0) return ans[x];
        int ret = x, m=rich[x].size();
        for (int i = 0;i < m;i++)
            if (quiet[dfs(rich[x][i], rich, quiet, ans)] < quiet[ret]) 
                ret = ans[rich[x][i]];
        ans[x] = ret;
        return ret;
        
    }
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<vector<int>> rich(n);
        int m = richer.size();
        for (int i = 0;i < m;i++)
            rich[richer[i][1]].push_back(richer[i][0]);
        vector<int> ans(n, -1);
        for (int i = 0;i < n;i++)
            if (ans[i]<0) dfs(i, rich, quiet, ans);
        return ans;
    }
};