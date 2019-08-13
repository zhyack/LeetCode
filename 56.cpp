
bool operator < (const vector<int>& A, const vector<int>& B){
    return A[0]<B[0] || A[0]==B[0] && A[1] < B[1];
}
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size()==0) return intervals;
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ret;
        int n = 1;
        ret.push_back(intervals[0]);
        for (auto i:intervals){
            if (i[0]<=ret[n-1][1]) ret[n-1][1] = max(ret[n-1][1], i[1]);
            else ret.push_back(i), n++;
        }
        return ret;
    }
};