class Solution {
public:
    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        int n = workers.size(), m=bikes.size();
        vector<vector<int>> states(m);
        for (int i = 1;i < (1<<m); i++){
            int cnt = 0, k = i;
            while(k){
                if (k&1) cnt++;
                k/=2;
            }
            // cout << cnt << "," << i << endl;
            states[cnt-1].push_back(i);
        }
        // cout << "states ready" << endl;
        vector<int> dp(1<<m, -1);
        dp[0]=0;
        int ret = -1;
        for (int i = 0;i < n; i++){
            for (int s:states[i]){
                for (int k = 0; k < m; k++)
                    if (s&(1<<k)){
                        int op = dp[s-(1<<k)] + abs(workers[i][0]-bikes[k][0]) + abs(workers[i][1]-bikes[k][1]);
                        if (dp[s]==-1 || dp[s]>op) dp[s]=op;
                        
                    }
                if (i==n-1){
                    if (ret==-1) ret=dp[s];
                    else ret=min(ret, dp[s]);
                }
            }
        }
        return ret;
    }
};