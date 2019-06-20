class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dp(n, vector<int>(n, -222));
        dp[0][0]=grid[0][0];
        for (int i=1;i < n*2-1;i++){
            for (int j1=min(i,n-1); j1 >= max(0,i-n+1) ; j1--)
                for (int j2=min(i,n-1); j2 >= max(0,i-n+1) ; j2--){
                    int c1 = i-j1, c2=i-j2, dpv=-222;
                    if (grid[c1][j1]==-1 || grid[c2][j2]==-1){
                        dp[j1][j2]=-222;
                        continue;
                    }
                    if (c1>0 && c2>0) dpv=max(dpv, dp[j1][j2]);
                    if (c1>0 && j2>0) dpv=max(dpv, dp[j1][j2-1]);
                    if (j1>0 && c2>0) dpv=max(dpv, dp[j1-1][j2]);
                    if (j1>0 && j2>0) dpv=max(dpv, dp[j1-1][j2-1]);
                    if (j1==j2) dp[j1][j2]=dpv+grid[c1][j1];
                    else dp[j1][j2]=dpv+grid[c1][j1]+grid[c2][j2];
                }
        }
        return max(dp[n-1][n-1],0);
    }
};