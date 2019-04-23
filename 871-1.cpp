class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        stations.insert(stations.begin(), vector<int>({0,0}));
        stations.push_back(vector<int>({target,0}));
        int n = stations.size();
        vector<vector<long long>> dp(n, vector<long long>(n, -1e18));
        dp[0][0]=startFuel;
        for (int i=1; i < n;i++)
            for (int j = 1; j <= i;j++)
                for (int k=j-1; k < i; k++)
                    if (dp[k][j-1]-stations[i][0]+stations[k][0]>=0)
                        dp[i][j] = max(dp[i][j], dp[k][j-1]-stations[i][0]+stations[k][0]+stations[i][1]);
        for (int i=1;i<n;i++)
            if (dp[n-1][i]>=0) return i-1;
        return -1;
    }
};