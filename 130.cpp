class Solution {
public:
    const int dir4[4][2]={{1,0}, {-1,0}, {0,1}, {0,-1}};
    void dfs(int x, int y, vector<vector<char>>& board){
        if (board[x][y]=='X') return;
        board[x][y]='.';
        for (int k = 0;k < 4;k++){
            int nx=x+dir4[k][0], ny=y+dir4[k][1];
            if (nx>=0 && nx<board.size() && ny>=0 && ny<board[0].size() && board[nx][ny]=='O')
                dfs(nx, ny, board);
        }
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        if (n==0) return;
        int m = board[0].size();
        if (m==0) return;
        for (int i = 0;i < n;i++) dfs(i,0, board), dfs(i,m-1, board);
        for (int i = 1;i < m-1;i++) dfs(0,i, board), dfs(n-1,i, board);
        for (int i = 0;i < n;i++)
            for (int j = 0; j < m;j ++)
                if (board[i][j]=='O') board[i][j]='X';
                else if (board[i][j]=='.') board[i][j]='O'; 
    }
};