class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n<=1) return 0;
        vector<int> sum(n, 0);
        int hind, ret=0;
        sum[0]=height[0];
        for (int i = 1;i < n;i++) sum[i]=sum[i-1]+height[i];
        hind=0;
        for (int i = 1;i < n;i++) 
            if (height[i]>=height[hind]){
                ret += height[hind]*(i-hind-1)-(sum[i-1]-sum[hind]);
                hind=i;
            }
        int f = hind;
        hind=n-1;
        for (int i = n-2;i >= f;i--) 
            if (height[i]>=height[hind]){
                ret += height[hind]*(hind-i-1)-(sum[hind-1]-sum[i]);
                hind=i;
            }
        return ret;
        
    }
};