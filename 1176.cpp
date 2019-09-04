class Solution {
public:
    int dietPlanPerformance(vector<int>& calories, int k, int lower, int upper) {
        int n = calories.size();
        if (n==0) return 0;
        vector<long long> sum(n+1, 0);
        for (int i = 0;i < n;i++) sum[i+1] = sum[i]+calories[i];
        int ret = 0;
        for (int i = k;i <= n;i++){
            if (sum[i]-sum[i-k]<lower) ret--;
            else if (sum[i]-sum[i-k]>upper) ret++;
        }
        return ret;
    }
};