bool dfs(vector<double> &a){
    int n = a.size();
    if (n==1){
        if (abs(a[0]-24)<1e-10) return true;
        else return false;
    }
    for (int i = 0;i < n;i++){
        for (int j = i+1;j < n;j++){
            vector<double> next({0});
            for (int k = 0;k < n;k++) if (k!=i && k!=j) next.push_back(a[k]);
            next[0] = a[i]+a[j];
            if (dfs(next)) return true;
            next[0] = a[i]-a[j];
            if (dfs(next)) return true;
            next[0] = a[j]-a[i];
            if (dfs(next)) return true;
            next[0] = a[i]*a[j];
            if (dfs(next)) return true;
            if (a[j]!=0){
                next[0] = a[i]/a[j];
                if (dfs(next)) return true;
            }
            if (a[i]!=0){
                next[0] = a[j]/a[i];
                if (dfs(next)) return true;
            }
        }
    }
    return false;
}
class Solution {
public:
    bool judgePoint24(vector<int>& nums) {
        vector<double> a;
        for (int i:nums) a.push_back(i);
        return dfs(a);
    }
};