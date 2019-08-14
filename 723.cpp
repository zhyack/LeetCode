bool check_stable(int n, int m, vector<vector<int>>& board){
    vector<vector<bool>> crash(n, vector<bool>(m, false));
    for (int i = 0;i < n;i++){
        int st = 0;
        int cnt = 0;
        for (int j = 0;j <= m;j++){
            if (j<m && board[i][j]==board[i][st]) cnt++;
            else{
                if (cnt>=3 && board[i][st]!=0)
                    for (int k = st;k < j;k++) crash[i][k]=true;
                st=j;
                cnt=1;
            }
        }
    }
    for (int j = 0;j < m;j++){
        int st = 0;
        int cnt = 0;
        for (int i = 0;i <= n;i++){
            if (i<n && board[i][j]==board[st][j]) cnt++;
            else{
                if (cnt>=3 && board[st][j]!=0)
                    for (int k = st;k < i;k++) crash[k][j]=true;
                st=i;
                cnt=1;
            }
        }
    }
    bool ret = true;
    for (int j = 0;j<m;j++){
        vector<int> left;
        for (int i = n-1;i>=0;i--)
            if (!crash[i][j]) left.push_back(board[i][j]);
        if (left.size()<n) ret=false;
        for (int k = 0;k < left.size();k++) board[n-1-k][j]=left[k];
        for (int k = left.size(); k<n;k++) board[n-1-k][j]=0;
    }
    return ret;
}

class Solution {
public:
    vector<vector<int>> candyCrush(vector<vector<int>>& board) {
        int n = board.size();
        if (n==0) return board;
        int m = board[0].size();
        if (m==0) return board;
        while(!check_stable(n,m,board));
        return board;
    }
};