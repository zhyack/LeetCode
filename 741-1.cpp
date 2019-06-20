class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dp(n, vector<int>(n, -222));
        dp[0][0]=0;
        for (int i=0;i < n;i++){
            for (int j1=n-1; j1>=0; j1--){
                if (grid[j1][i]==-1){
                    for (int j2=n-1; j2>=j1;j2--) dp[j1][j2]=-222;
                    continue;
                }
                for (int j2=n-1; j2>=j1; j2--){
                    if (grid[j2][i]==-1){
                            dp[j1][j2]=-222;
                            continue;
                        }
                    int sum1 = 0;
                    for (int k1=j1; k1>=0; k1--){
                        if (grid[k1][i]==-1) break;
                        sum1 += grid[k1][i];                    
                        int sum2 = 0;
                        for (int k2=j2; k2>=k1; k2--){
                            if (grid[k2][i]==-1) break;
                            if (k2>j1) sum2 += grid[k2][i];
                            dp[j1][j2] = max(dp[j1][j2], dp[k1][k2]+sum1+sum2);
                        }
                    }
                }
            }
        }
        return max(dp[n-1][n-1],0);
    }
};