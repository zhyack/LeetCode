class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ret;
        vector<int> brand(2,-1);
        bool deal = false;
        for (auto v:intervals){
            if (v[1]<newInterval[0] || v[0]>newInterval[1]){
                if (brand[0]!=-1){
                    ret.push_back(brand);
                    brand[0] = brand[1] = -1;
                    deal = true;
                }
                if (!deal && v[0]>newInterval[1]){
                    ret.push_back(newInterval);
                    deal = true;
                }
                ret.push_back(v);
                continue;
            }
            if (v[1]>=newInterval[0]) brand[0]=min(min(v[0], brand[0]==-1?v[0]:brand[0]), newInterval[0]);
            if (v[0]<=newInterval[1]) brand[1]=max(v[1], newInterval[1]);
        }
        if (!deal){
            if (brand[0]!=-1) ret.push_back(brand);
            else ret.push_back(newInterval);
        }
        return ret;
    }
};