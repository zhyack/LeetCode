class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        long long b = 1, ret=0;
        for (int i = 0; i < 32; i++){
            int zs=0, os=0;
            for (int n:nums){
                if (n&b) os++;
                else zs++;
            }
            ret += zs*os;
            b<<=1;
        }
        return ret;
    }
};