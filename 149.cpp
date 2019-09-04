class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n==0) return 0;
        int ret = 0;
        unordered_map<int, int> mrc;
        mrc.clear();
        for (auto p:points) mrc[p[0]]++;
        for (auto it:mrc) ret=max(ret,it.second);
        mrc.clear();
        for (auto p:points) mrc[p[1]]++;
        for (auto it:mrc) ret=max(ret,it.second);
        unordered_map<int, unordered_map<long double, int>> m;
        mrc.clear();
        for (int i = 0;i < n;i++)
            for (int j = i+1; j< n;j++){
                if (points[i][0]!=points[j][0] && points[i][1]!=points[j][1]){
                    long double k = (long double)(points[j][1]-points[i][1])/(long double)(points[j][0]-points[i][0]);
                    m[i][k]++;
                    m[j][k]++;
                    ret=max(ret, m[i][k]+1+mrc[i]);
                }
                else if (points[i][0]==points[j][0] && points[i][1]==points[j][1]){
                    mrc[i]++;
                    mrc[j]++;
                    ret=max(ret, 1+mrc[i]);
                }
            }
        return ret;
    }
};