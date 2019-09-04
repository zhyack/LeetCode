class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int n = weights.size();
        int l = 0, r = 0;
        for (int i = 0;i < n-D+1;i++) r+=weights[i], l=max(l,weights[i]);
        for (int i = n-D+1; i < n;i++) r = max(r, weights[i]), l = max(l, weights[i]);
        while(l<r){
            int m = (l+r)/2;
            int need = 0, sum=0;
            for (int i = 0;i < n;i++){
                if (sum+weights[i]>m){
                    need++;
                    sum=0;
                    if (need>D) break;
                }
                sum+=weights[i];
            }
            need++;
            if (need<=D) r=m;
            else l=m+1;
        }
        return l;
    }
};