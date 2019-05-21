class Solution {
public:
    const int dir4[4][2]={{1,0}, {-1,0}, {0,1}, {0,-1}};
    int top(int x, vector<int>& father){
        if (x!=father[x]) father[x]=top(father[x], father);
        return father[x];
    }
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> father(n*n);
        vector<int> m(n*n);
        for (int i = 0;i < n;i++)
            for (int j = 0;j < n;j++){
                father[grid[i][j]]=grid[i][j];
                m[grid[i][j]]=i*n+j;
            }
        for (int i = 0;i < n*n;i++){
            int x = m[i]/n, y=m[i]%n;
            for (int j = 0;j < 4;j++){
                int nx = x+dir4[j][0], ny=y+dir4[j][1];
                if (nx>=0 && nx<n && ny>=0 && ny<n && grid[nx][ny]<=i){
                    int fx = top(i, father), fy=top(grid[nx][ny], father);
                    if (fx!=fy) father[fx]=fy;
                }
            }
            int fs=top(grid[0][0], father), ft=top(grid[n-1][n-1], father);
            if (fs==ft) return i;
        }
        return n*n;
    }
};