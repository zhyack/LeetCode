class Solution {
public:
    int minTransfers(vector<vector<int>>& transactions) {
        unordered_map<int, int> m;
        for (auto t:transactions){
            m[t[0]]+=t[2];
            m[t[1]]-=t[2];
        }
        vector<int> g1, g2;
        for (auto it:m){
            if (it.second>0) g1.push_back(it.second);
            else if (it.second<0) g2.push_back(-it.second);
        }
        int n1 = g1.size(), n2 = g2.size();
        int ret = n1+n2;
        vector<vector<int>> dp(1<<n1, vector<int>(1<<n2, 0));
        dp[0][0]=0;
        vector<int> s1(1<<n1, 0), s2(1<<n2, 0);
        for (int si = 0; si < 1<<n1; si++)
            for (int i = 0;i < n1;i++){
                if ((si&(1<<i)) == 0) continue;
                int prev_si = si-(1<<i);
                s1[si]=s1[prev_si]+g1[i];
                for (int sj = 0; sj < 1<<n2; sj++)
                    for (int j = 0;j < n2;j++){
                        if ((sj&(1<<j)) == 0) continue;
                        int prev_sj = sj-(1<<j);
                        s2[sj]=s2[prev_sj]+g2[j];
                        int past = 0;
                        past=max(past, dp[prev_si][prev_sj]);
                        past=max(past, dp[si][prev_sj]);
                        past=max(past, dp[prev_si][sj]);
                        if (s1[si]==s2[sj]) past++;
                        dp[si][sj] = max(dp[si][sj], past);
                    }
            }
        return ret-dp[(1<<n1)-1][(1<<n2)-1];
                                      
    }
};