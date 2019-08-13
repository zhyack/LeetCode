int top(int x, vector<int>& f){
    if (f[x]!=x) f[x]=top(f[x], f);
    return f[x];
}
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        unordered_map<int, vector<int>> mr, mc;
        for (int i =0;i < n;i++){
            mr[stones[i][0]].push_back(i);
            mc[stones[i][1]].push_back(i);
        }
        vector<int> father(n);
        for (int i = 0;i < n;i++) father[i]=i;
        for (auto it:mr){
            int mn = it.second.size();
            for (int k = 1;k < mn; k++){
                int fx = top(it.second[k-1], father), fy = top(it.second[k], father);
                if (fx!=fy) father[fx]=fy;
            }
        }
        for (auto it:mc){
            int mn = it.second.size();
            for (int k = 1;k < mn; k++){
                int fx = top(it.second[k-1], father), fy = top(it.second[k], father);
                if (fx!=fy) father[fx]=fy;
            }
        }
        int left = 0;
        for (int i = 0;i < n;i++)
            if (top(i, father)==i) left++;
        return n-left;
    }
};