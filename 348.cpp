class TicTacToe {
public:
    /** Initialize your data structure here. */
    unordered_map<int, int> cnt[2];
    int bn, win_state;
    TicTacToe(int n) {
        cnt[0].clear();
        cnt[1].clear();
        bn = n;
        win_state=0;
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        if (win_state) return win_state;
        cnt[player-1][row+bn]++;
        cnt[player-1][col]++;
        if (row==col) cnt[player-1][-1]++;
        if (row+col==bn-1) cnt[player-1][-2]++;
        if (cnt[player-1][row+bn]==bn || cnt[player-1][col]==bn || cnt[player-1][-1]==bn || cnt[player-1][-2]==bn)
            win_state = player;
        return win_state;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */