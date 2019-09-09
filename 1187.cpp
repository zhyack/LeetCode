class Solution {
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        // dp[i][j][1]=dp[i-1][k][0]+1(j>a[i-1]) , dp[i-1][k][1]+1 (b[k]<b[j])
        // dp[i][j][0]=dp[i-1][k][0] (a[i]>a[i-1]), dp[i-1][k][1] (a[i]>b[k])
        int n = arr1.size(), m = arr2.size();
        sort(arr2.begin(), arr2.end());
        vector<vector<int>> dp0(n, vector<int>(m, 1e9+7)), dp1(n, vector<int>(m, 1e9+7));
        for (int i = 0;i < n;i++){
            if (i>0 && arr1[i]<=arr1[i-1]) break;
            dp0[i][0]=0;
        }
        for (int i = 0;i < n;i++){
            if (i>0 && arr2[0]<=arr1[i-1]) break;
            dp1[i][0]=1;
            if (i>0 && arr1[i]<=arr1[i-1]) break;
        }
        for (int j = 0;j < m;j++) dp0[0][j]=0, dp1[0][j]=1;
        for (int i = 1;i < n;i++){
            int k = 0;
            while(k<m && arr2[k]<arr1[i]) k++;   
            int t = -1;
            for (int j = 0;j < m;j++){
                if (j==0 || arr2[j]!=arr2[j-1]) t=j;
                if (arr1[i]>arr1[i-1]) dp0[i][j]=min(dp0[i][j], dp0[i-1][j]);
                if (k>0) dp0[i][j]=min(dp0[i][j], dp1[i-1][min(k-1,j)]);
                if (arr2[j]>arr1[i-1]) dp1[i][j]=min(dp1[i][j], dp0[i-1][j]+1);
                if (j>0&&t>0) dp1[i][j]=min(dp1[i][j], dp1[i-1][t-1]+1);
                // cout << i << "," << j << ":" << dp0[i][j] << ", " << dp1[i][j] << endl;
            }
            
        } 
        int ret=1e9+7;
        for (int j = 0;j < m;j++) ret = min(ret, min(dp0[n-1][j], dp1[n-1][j]));
        if (ret==1e9+7) return -1;
        return ret;
    }
};