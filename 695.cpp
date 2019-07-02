const int dir[4][2]={0,1,0,-1,1,0,-1,0};

int dfs(int x, int y, vector<vector<int>> &g, vector<vector<bool>> &v){
    int n = g.size(), m = g[0].size(), ret=1;
    v[x][y]=true;
    for (int k = 0;k < 4; k++){
        int nx = x+dir[k][0], ny = y+dir[k][1];
        if (nx>=0 && nx<n && ny>=0 && ny<m && g[nx][ny] && !v[nx][ny])
            ret += dfs(nx, ny, g, v);
    }
    return ret;
}

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n==0) return 0;
        int m = grid[0].size();
        if (m==0) return 0;
        vector<vector<bool>> v(n, vector<bool>(m, false));
        int ret = 0;
        for (int i = 0;i < n;i++)
            for (int j = 0;j < m;j++)
                if (grid[i][j]&&!v[i][j])
                    ret = max(ret, dfs(i,j,grid,v));
        return ret;
    }
};