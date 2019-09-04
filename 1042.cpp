class Solution {
public:
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        vector<unordered_set<int>> edges(N+1);
        for (auto p:paths) edges[p[0]].insert(p[1]), edges[p[1]].insert(p[0]);
        vector<int> ret(N,-1);
        vector<vector<bool>> can(N+1, vector<bool>(4, true));
        for (int i = 1;i <= N;i++){
            if (ret[i-1]==-1){
                queue<int> q;
                q.push(i);
                while(!q.empty()){
                    int x = q.front();
                    q.pop();
                    for (int k = 0;k < 4;k++)
                        if (can[x][k]){
                            ret[x-1]=k;
                            break;
                        }
                    for (auto y:edges[x]){
                        can[y][ret[x-1]]=false;
                        if (ret[y-1]==-1) q.push(y);
                    }
                }
            }
        }
        for (int i = 0;i < N;i++) ret[i]++;
        return ret;
    }
};