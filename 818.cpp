class Solution {
public:
    int racecar(int target) {
        vector<int> dp(target*2+1, target*4);
        int w = 1, v = 1;
        dp[target]=-1;
        while(w <= target){
            dp[target+w]=v;
            w=w*2+1;
            v++;
        }
        for (int wp=0, vp=1; wp<=target*2; wp=wp*2+1,vp++){
            for (int wn=0, vn=1; wn<=target*2; wn=wn*2+1,vn++){
                w = wp-wn;
                v = vp+vn;
                if (w>0) for (int i = target*2; i>=w; i--) dp[i] = min(dp[i], dp[i-w]+v);
                else if (w<0) for (int i = 0; i<=target*2+w; i++) dp[i] = min(dp[i], dp[i-w]+v);
            }
        }
        return dp[target*2];
        
    }
};