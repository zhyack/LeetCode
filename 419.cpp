class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int n = board.size();
        if (n==0) return 0;
        int m = board[0].size();
        if (m==0) return 0;
        int ret = 0;
        for (int i = 0;i < n;i++)
            for (int j = 0;j < m;j++)
                if (board[i][j]=='X' && (i==0 && j==0 || i>0 && j>0 && board[i][j-1]=='.' 
                                        && board[i-1][j]=='.' || i>0 && j==0 && board[i-1][j]=='.'
                                        || j>0 && i==0 && board[i][j-1]=='.')) ret++;
        return ret;
    }
};