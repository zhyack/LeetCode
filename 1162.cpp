const int dirs[4][2] = {0,1,1,0,0,-1,-1,0};
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n==0) return -1;
        int m = grid[0].size();
        if (m==0) return -1;
        queue<vector<int>> q;
        for (int i = 0;i < n;i ++)
            for (int j = 0;j < m;j++)
                if (grid[i][j]) q.push(vector<int>({i,j,0}));
        if (q.empty()) return -1;
        int ret = 0;
        while(!q.empty()){
            vector<int> v = q.front();
            q.pop();
            ret = max(v[2], ret);
            for (int d = 0;d < 4;d++){
                int nx = v[0]+dirs[d][0],  ny = v[1]+dirs[d][1];
                if (nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny]==0) q.push(vector<int>{nx, ny, v[2]+1}), grid[nx][ny]=1;
            }
        }
        if (ret==0) ret = -1;
        return ret;
    }
};