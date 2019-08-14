class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        if (n==0) return 0;
        int m = matrix[0].size();
        if (m==0) return 0;
        vector<vector<int>> dp(n, vector<int>(m,0));
        int ret = 0;
        stack<pair<int, int>> s;
        for (int i = 0;i < n;i++){
            for (int j = 0;j < m;j++){
                if (matrix[i][j]=='1' && i>0) dp[i][j]=dp[i-1][j]+1;
                else if (matrix[i][j]=='1') dp[i][j]=1;
                else dp[i][j]=0;
                // cout << dp[i][j] << " ";
            }
            // cout << endl;
            for (int j = 0;j <= m;j++){
                int h = -1, t=j;
                if (j<m) h=dp[i][j];
                while(!s.empty() && s.top().first>h){
                    ret = max(ret, (j-s.top().second)*s.top().first);
                    t = s.top().second;
                    s.pop();
                }
                if (j<m) s.push(make_pair(h, t));
            }
        }
        return ret;
    }
};