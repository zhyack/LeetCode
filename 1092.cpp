class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n1 = str1.length(), n2 = str2.length();
        vector<vector<int>> dp(n1, vector<int>(n2, 0)), from(n1, vector<int>(n2, -1));
        for (int i = 0;i < n1;i++)
            for (int j = 0;j < n2;j++){
                if (i>0 && dp[i-1][j]>dp[i][j]){
                    dp[i][j]=dp[i-1][j];
                    from[i][j]=0;
                }
                if (j>0 && dp[i][j-1]>dp[i][j]){
                    dp[i][j]=dp[i][j-1];
                    from[i][j]=1;
                }
                if (str1[i]==str2[j]){
                    if (i==0 || j==0) dp[i][j]=1, from[i][j]=2;
                    else if (dp[i-1][j-1]+1>dp[i][j]) dp[i][j]=dp[i-1][j-1]+1, from[i][j]=2;
                }
            }
        vector<bool> m1(n1, false), m2(n2, false);
        int x = n1-1, y=n2-1;
        while(x>=0 && y>=0 && from[x][y]!=-1){
            if (from[x][y]==2) m1[x]=m2[y]=true, x-=1, y-=1;
            else if (from[x][y]==1) y-=1;
            else if (from[x][y]==0) x-=1;
        }
        string ret="";
        x = 0, y = 0;
        while(x<n1 || y <n2){
            while(x<n1 && !m1[x]) ret.append(1,str1[x++]);
            while(y<n2 && !m2[y]) ret.append(1,str2[y++]);
            if (x<n1 && y<n2){
                ret.append(1,str1[x]);
                x++, y++;
            }
        }
        return ret;
    }
};