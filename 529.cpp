const int dirs[8][2]={0,1,0,-1,1,0,-1,0,1,1,-1,-1,1,-1,-1,1};
class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int n = board.size();
        if (n==0) return board;
        int m = board[0].size();
        if (m==0) return board;
        queue<pair<int,int>> q;
        q.push(make_pair(click[0], click[1]));
        while(!q.empty()){
            int x = q.front().first, y = q.front().second;
            q.pop();
            if (board[x][y]=='M'){
                board[x][y]='X';
                return board;
            }
            if (board[x][y]=='B' || board[x][y]>='1' && board[x][y]<='8') continue;
            int cnt = 0;
            for (int d = 0;d < 8;d++){
                int nx = x+dirs[d][0], ny = y+dirs[d][1];
                if (nx>=0 && nx < n && ny>=0 && ny<m && board[nx][ny]=='M') cnt++;
            }
            if (cnt) board[x][y]=char('0'+cnt);
            else{
                board[x][y] = 'B';
                for (int d = 0;d < 8;d++){
                    int nx = x+dirs[d][0], ny = y+dirs[d][1];
                    if (nx>=0 && nx < n && ny>=0 && ny<m && board[nx][ny]=='E') q.push(make_pair(nx, ny));
                }
            }
        }
        return board;
    }
};