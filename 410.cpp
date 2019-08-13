bool check(long long ss, int m, vector<int>&nums){
    long long p = 0, s = 0, c = 0, n = nums.size();
    while(p < n){
        if (s+nums[p]>ss){
            c++;
            s = 0;
        }
        s += nums[p++];
    }
    c++;
    return c<=m;
}

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        long long sum = 0, mv=0;
        for (int i = 0;i < n;i++){
            sum += nums[i];
            mv = max(mv, (long long)nums[i]);
        }
        long long l = mv, r = sum;
        while(l < r){
            long long ss = (l+r)/2;
            if (check(ss, m , nums)) r = ss;
            else l=ss+1;
        }
        return l;
    }
};