bool dfs(int d, vector<pair<int, int>> &blanks, vector<vector<char>>& board, vector<unordered_set<int>>& row, vector<unordered_set<int>>& col, vector<unordered_set<int>>& chunk){
    if (d==blanks.size()) return true;
    int r=blanks[d].first, c=blanks[d].second;
    int k=r/3*3+c/3;
    vector<int> to_deal;
    for (int i:chunk[k]) to_deal.push_back(i);
    for (int i:to_deal){
        if (row[r].find(i)!=row[r].end() && col[c].find(i)!=col[c].end()){
            chunk[k].erase(i);
            row[r].erase(i);
            col[c].erase(i);
            board[r][c]=char(i+'0');
            if (dfs(d+1,blanks, board, row, col, chunk)) return true;
            board[r][c]='.';
            chunk[k].insert(i);
            row[r].insert(i);
            col[c].insert(i);
        }
    }
    return false;
}

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<unordered_set<int>> row(9), col(9), chunk(9);
        for (int i = 0;i < 9; i++)
            for (int j = 0;j < 9; j++)
                row[i].insert(j+1), col[i].insert(j+1), chunk[i].insert(j+1);
        vector<pair<int, int>> blanks;
        for (int i = 0;i < 9;i++)
            for (int j = 0;j < 9;j++)
                if (board[i][j]=='.')
                    blanks.push_back(make_pair(i,j));
                else{
                    row[i].erase(board[i][j]-'0');
                    col[j].erase(board[i][j]-'0');
                    chunk[i/3*3+j/3].erase(board[i][j]-'0');
                }
        dfs(0, blanks, board, row, col, chunk);
    }
};