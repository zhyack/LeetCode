const int dir[4][2]={0,1,0,-1,1,0,-1,0};
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n==0) return 0;
        int m = grid[0].size();
        if (m==0) return 0;
        vector<vector<bool>> v(n, vector<bool>(m, false));
        queue<int> q;
        int ret = 0;
        for (int i = 0;i < n;i++)
            for (int j = 0; j < m;j++)
                if (grid[i][j] && !v[i][j]){
                    q.push(i);
                    q.push(j);
                    v[i][j]=true;
                    int cnt = 1;
                    while(!q.empty()){
                        int x = q.front();
                        q.pop();
                        int y = q.front();
                        q.pop();
                        for (int k = 0;k < 4;k++){
                            int nx = x+dir[k][0], ny = y+dir[k][1];
                            if (nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny] && !v[nx][ny]){
                                q.push(nx);
                                q.push(ny);
                                v[nx][ny]=true;
                                cnt++;
                            }
                        }
                    }
                    ret = max(ret, cnt);
                }
        return ret;
    }
};