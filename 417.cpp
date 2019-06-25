const int dir[4][2]={0,1,0,-1,1,0,-1,0};

vector<vector<bool>> getFlow(vector<vector<int>> &matrix, int sr, int sc){
    queue<int> qx, qy;
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<bool>> ret(n, vector<bool>(m, false));
    for (int i = 0;i < n; i++) qx.push(i), qy.push(sc), ret[i][sc]=true;
    for (int j = 0;j < m; j++) qx.push(sr), qy.push(j), ret[sr][j]=true;
    while(!qx.empty()){
        int x = qx.front(), y = qy.front();
        qx.pop(), qy.pop();
        for (int k = 0;k < 4; k++){
            int nx = x+dir[k][0], ny = y+dir[k][1];
            if (nx>=0 && nx < n && ny>=0 && ny<m && !ret[nx][ny] && matrix[x][y]<=matrix[nx][ny])
                qx.push(nx), qy.push(ny), ret[nx][ny]=true;
        }
    }
    return ret;
}

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<vector<int>> ret;
        int n = matrix.size();
        if (n==0) return ret;
        int m = matrix[0].size();
        if (m==0) return ret;
        vector<vector<bool>> p = getFlow(matrix, 0, 0);
        vector<vector<bool>> a = getFlow(matrix, n-1, m-1);
        for (int i = 0;i < n; i++)
            for (int j = 0;j < m; j++)
                if (p[i][j] && a[i][j])
                    ret.push_back(vector<int>({i, j}));
        return ret;
    }
};