const int dirs[4][2]={1,0,-1,0,0,1,0,-1};
int dfs(int x, int y, vector<vector<int>>& dp, vector<vector<int>>& mat){
    if (~dp[x][y]) return dp[x][y];
    dp[x][y] = 1;
    for (int d = 0;d < 4;d++){
        int nx = x+dirs[d][0], ny = y+dirs[d][1];
        if (nx>=0 && nx<dp.size() && ny>=0 && ny<dp[0].size() && mat[nx][ny]<mat[x][y])
            dp[x][y] = max(dp[x][y], dfs(nx, ny, dp, mat)+1);
    }
    return dp[x][y];
}

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (n==0) return 0;
        int m = matrix[0].size();
        if (m==0) return 0;
        vector<vector<int>> dp(n, vector<int>(m, -1));
        int ret = 0;
        for (int i = 0;i < n;i++)
            for (int j = 0;j < m;j++)
                ret = max(ret, dfs(i, j, dp, matrix));
        return ret;
    }
};