const int dirs[4][2]={0,1,0,-1,1,0,-1,0};
struct Node{
    int x, y, d;
    Node(int xx, int yy, int dd=0){
        x = xx;
        y = yy;
        d = dd;
    }
};

void dfs(int x, int y, vector<vector<bool>> &visited, vector<vector<char>> &grid){
    stack<Node> s;
    s.push(Node(x,y));
    int n = grid.size(), m = grid[0].size();
    while(!s.empty()){
        Node t = s.top();
        s.pop();
        // cout << t.x << "," << t.y << ","  << t.d << endl;
        visited[t.x][t.y]=true;
        if (t.d>=4) continue;
        s.push(Node(t.x, t.y, t.d+1));
        int nx = t.x+dirs[t.d][0], ny = t.y+dirs[t.d][1];
        if (nx>=0 && nx<n && ny>=0 && ny<m && !visited[nx][ny] && grid[nx][ny]=='1') s.push(Node(nx, ny));
    }
}

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        if (n==0) return 0;
        int m = grid[0].size();
        if (m==0) return 0;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int ret = 0;
        for (int i = 0;i < n;i++)
            for (int j = 0;j < m;j++)
                if (!visited[i][j] && grid[i][j]=='1') dfs(i,j,visited,grid), ret++;
        return ret;
    }
};