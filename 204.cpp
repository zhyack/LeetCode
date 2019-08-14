class Solution {
public:
    int countPrimes(int n) {
        vector<bool> is_prime(n+2, true);
        is_prime[0]=is_prime[1]=false;
        int ret = 0;
        for (int i = 2;i < n;i++)
            if (is_prime[i]){
                ret++;
                for (int k = 2; k*i < n; k++) is_prime[i*k]=false;
            }
        return ret;
    }
};