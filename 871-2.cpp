class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        stations.insert(stations.begin(), vector<int>({0,0}));
        stations.push_back(vector<int>({target,0}));
        int n = stations.size();
        vector<long long> dp(n, -1e18);
        dp[0]=startFuel;
        for (int i=1; i < n;i++){
            for (int j=0; j<i;j++){
                dp[j]-=stations[i][0]-stations[i-1][0];
                if (dp[j]<0) dp[j]=-1e18;
            }
            for (int j=i; j>=1;j--)
                dp[j] = max(dp[j], dp[j-1]+stations[i][1]);
        }
        for (int i=0;i<n;i++)
            if (dp[i]>=0) return i;
        return -1;
    }
};