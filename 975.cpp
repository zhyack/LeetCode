int dfs(int x, int o, vector<int> &dp0, vector<int> &dp1, vector<int> &odd, vector<int> &even){
    if (x==-1) return 0;
    if (o==0 && dp0[x]>=0) return dp0[x];
    if (o==1 && dp1[x]>=0) return dp1[x];
    if (o==0) dp0[x] = dfs(odd[x], 1, dp0, dp1, odd, even);
    else dp1[x] = dfs(even[x], 0, dp0, dp1, odd, even);
    if (o==0) return dp0[x];
    else return dp1[x];
}

class Solution {
public:
    int oddEvenJumps(vector<int>& A) {
        int n = A.size();
        vector<int> odd(n,-1), even(n,-1);
        map<int, int> m;
        m.clear();
        m[-1] = -1;
        m[10000001] = -1;
        for (int i = n-1;i >=0 ;i--){
            auto it = m.lower_bound(A[i]);
            if (it->first==A[i]) odd[i]=even[i]=it->second;
            else{
                odd[i]=it->second;
                it--;
                even[i]=it->second;
            }
            m[A[i]]=i;
        }
        vector<int> dp_odd(n, -1), dp_even(n, -1);
        dp_odd[n-1] = dp_even[n-1] = 1;
        for (int i = 0;i < n-1; i++) dfs(i, 0, dp_odd, dp_even, odd, even);
        int ret = 0;
        for (int i = 0;i < n;i++)
            if (dp_odd[i]==1) ret++;
        return ret;
    }
};