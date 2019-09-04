const int dirs[4][2]={0,1,0,-1,1,0,-1,0};
bool dfs(int x, int y, int d, string target, vector<vector<char>>& board, vector<vector<bool>>& visited){
    if (d==target.length()) return true;
    visited[x][y]=true;
    for (int k = 0;k < 4;k++){
        int nx = x+dirs[k][0], ny = y+dirs[k][1];
        if (nx>=0 &&  nx<board.size() && ny>=0 && ny<board[0].size() && !visited[nx][ny] && board[nx][ny]==target[d]){
            if (dfs(nx, ny, d+1, target, board, visited)) return true;
        }
    }
    visited[x][y]=false;
    return false;
}

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        if (n==0) return false;
        int m = board[0].size();
        if (m==0) return false;
        if (word.length()==0) return true;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for (int i = 0;i < n;i++)
            for (int j = 0;j < m;j++)
                if (board[i][j]==word[0]){
                    if (dfs(i, j, 1, word, board, visited)) return true;
                }
        return false;
    }
};