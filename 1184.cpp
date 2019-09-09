class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int s = min(start, destination), t = max(start, destination);
        long long n = distance.size();
        long long total = 0, dis = 0;
        for (int i = 0;i < n;i++){
            if (i>=s && i<t) dis+=distance[i];
            total+=distance[i];
        }
        return min(dis, total-dis);
    }
};