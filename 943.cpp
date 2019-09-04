class Solution {
public:
    string shortestSuperstring(vector<string>& A) {
        int n = A.size();
        if (n==0) return "";
        vector<vector<int>> overlap(n, vector<int>(n,0));
        for (int i = 0;i < n;i++)
            for (int j = 0;j < n;j++)
                for (int k = min(A[i].length(), A[j].length());k > 0; k--)
                    if (A[i].substr(A[i].length()-k) == A[j].substr(0, k)){
                        overlap[i][j]=k;
                        break;
                    }
        vector<vector<int>> dp(1<<n, vector<int>(n, -1)), path(1<<n, vector<int>(n, -1));
        for (int s = 1; s < (1<<n); s++){
            for (int i = 0;i < n;i++){
                if (s&(1<<i)){
                    if (s-(1<<i)==0){
                        dp[s][i]=0;
                    }
                    for (int j = 0;j < n;j++){
                        if (j!=i && (s&(1<<j)) && dp[s-(1<<i)][j]+overlap[j][i]>dp[s][i]){
                            dp[s][i]=dp[s-(1<<i)][j]+overlap[j][i];
                            path[s][i]=j; 
                        }
                    }
                }
            }
        }
        int ret_val = -1, ret_last = -1;
        for (int i = 0;i < n;i++)
            if (dp[(1<<n)-1][i]>ret_val){
                ret_val = dp[(1<<n)-1][i];
                ret_last = i;
            }
        // cout << ret_val << endl;
        vector<int> ret_path({ret_last});
        int s_last = (1<<n)-1;
        while(ret_last!=-1){
            // cout << s_last << ":" << ret_last << endl;
            int next_s = s_last-(1<<ret_last);
            ret_last = path[s_last][ret_last];
            if (ret_last!=-1) ret_path.push_back(ret_last);
            s_last = next_s;
        }
        reverse(ret_path.begin(), ret_path.end());
        // for (auto i:ret_path) cout << i << ",";
        // cout << endl;
        string ret = A[ret_path[0]];
        for (int i = 1;i < n;i++){
            ret += A[ret_path[i]].substr(overlap[ret_path[i-1]][ret_path[i]]);
        }
        return ret;
    }
};