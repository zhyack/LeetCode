const int MOD = 1e9+7;
class Solution {
public:
    int numPrimeArrangements(int n) {
        vector<long long> a(n+1, 0);
        a[0] = 1;
        for (int i = 1;i <= n;i++)
            a[i] = a[i-1]*i%MOD;
        vector<bool> is_prime(n+1, true);
        int cnt = 0;
        for (int i = 2;i <= n;i++){
            if (is_prime[i]) cnt++;
            for (int k = 2; k*i<=n; k++) is_prime[k*i]=false;
        }
        long long ret = a[cnt]*a[n-cnt]%MOD;
        return int(ret);
    }
};