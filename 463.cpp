class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n=grid.size();
        if (n==0) return 0;
        int m = grid[0].size();
        if (m==0) return 0;
        int cnt=0;
        for (int i = 0;i < n;i++)
            for (int j = 0;j < m; j++)
                if (grid[i][j]){
                    if (i==0 || grid[i-1][j]==0) cnt++;
                    if (j==0 || grid[i][j-1]==0) cnt++;
                    if (i==n-1 || grid[i+1][j]==0) cnt++;
                    if (j==m-1 || grid[i][j+1]==0) cnt++;
                }
        return cnt;
    }
};