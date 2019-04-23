class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n = stations.size();
        priority_queue<int> q;
        while(!q.empty()) q.pop();
        int ans = 0, greedy_len=startFuel, p=0;
        while(greedy_len<target){
            ans++;
            while(p<n && greedy_len>=stations[p][0]) q.push(stations[p++][1]);
            if (q.empty()) return -1;
            greedy_len += q.top();
            q.pop();
            if (greedy_len>=target) return ans;
        }
        return 0;
    }
};