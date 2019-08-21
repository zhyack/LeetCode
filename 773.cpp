const int dirs[4][2]={0,1,0,-1,1,0,-1,0};
int convert_board_int(vector<vector<int>>& board){
    return board[0][0]*100000+board[0][1]*10000+board[0][2]*1000+board[1][0]*100+board[1][1]*10+board[1][2];
}

vector<vector<int>> convert_int_board(int s){
    return vector<vector<int>>({{s/100000, s%100000/10000, s%10000/1000},{s%1000/100, s%100/10, s%10}});
}

class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        int start = convert_board_int(board);
        if (start==123450) return 0;
        unordered_map<int, int> solve;
        queue<int> q;
        q.push(start);
        solve[start]=0;
        while(!q.empty()){
            int s = q.front();
            q.pop();
            vector<vector<int>> b = convert_int_board(s);
            for (int i = 0;i < 2;i ++)
                for (int j = 0;j < 3;j++)
                    if (b[i][j]==0)
                        for (int k = 0;k < 4;k++){
                            int nx = i+dirs[k][0], ny=j+dirs[k][1];
                            if (nx>=0 && nx<2 && ny>=0 && ny<3){
                                swap(b[i][j], b[nx][ny]);
                                int ns = convert_board_int(b);
                                if (solve.find(ns)==solve.end()){
                                    solve[ns]=solve[s]+1;
                                    q.push(ns);
                                    if (ns==123450) return solve[ns];
                                }
                                swap(b[i][j], b[nx][ny]);
                            }
                        }
        }
        return -1;
    }
};