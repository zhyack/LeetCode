const int dirs[8][2]={1,2,2,1,2,-1,1,-2,-1,-2,-2,-1,-2,1,-1,2};
class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {
        vector<vector<vector<double>>> dp(2, vector<vector<double>>(N, vector<double>(N,0.0)));
        dp[0][r][c]=1.0;
        for (int i = 1;i <= K;i++){
            int c = i%2, l = 1-i%2;
            for (int x = 0; x < N;x++){
                for (int y = 0;y <N;y++){
                    if (dp[l][x][y]==0.0) continue;
                    for (int k = 0;k < 8;k++){
                        int nx = x+dirs[k][0], ny=y+dirs[k][1];
                        if (nx>=0 && nx<N && ny>=0 &&ny<N) dp[c][nx][ny]+=dp[l][x][y]*0.125;
                    }
                    dp[l][x][y]=0.0;
                }
            }
        }
        double ret = 0.0;
        for (int x = 0; x < N;x++)
            for (int y = 0;y <N;y++)
                ret += dp[K%2][x][y];
        return ret;
    }
};