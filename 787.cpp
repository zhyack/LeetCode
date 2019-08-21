class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        const int MAXP = 1000001;
        vector<vector<int>> prices(n, vector<int>(n, MAXP));
        prices[src][0]=0;
        queue<pair<int,int>> q;
        q.push(make_pair(src, 0));
        vector<vector<int>> edges(n, vector<int>(n, MAXP));
        for (auto f:flights)
            edges[f[0]][f[1]]=f[2];
        vector<int> in_queue(n, -1);
        in_queue[0] = 0;
        K = min(K, n-2);
        while(!q.empty()){
            auto item = q.front();
            q.pop();
            int x = item.first, d = item.second;
            if (d>K) break;
            for (int i = 0;i < n; i++){
                if (edges[x][i]!=MAXP && prices[i][d+1]>prices[x][d]+edges[x][i]){
                    prices[i][d+1] = prices[x][d]+edges[x][i];
                    // cout << "upd: " << i << " -> " << prices[i][d+1] << endl;
                    if (in_queue[i]<=d){
                        q.push(make_pair(i, d+1));
                        in_queue[i]=d+1;
                    }
                }
            }
        }
        int ans = MAXP;
        for (int i = 0;i <= K+1; i++)
            if (prices[dst][i]!=MAXP) ans = min(ans, prices[dst][i]);
        if (ans==MAXP) return -1;
        return ans;
    }
};