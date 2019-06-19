struct Node{
    int d, p;
};
bool operator <(const Node &A,const Node &B){
    return A.d < B.d;
}
class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = difficulty.size();
        vector<Node> jobs(0);
        Node tmp;
        tmp.d=tmp.p=0;
        jobs.push_back(tmp);
        for (int i = 0;i < n;i++){
            tmp.d = difficulty[i];
            tmp.p = profit[i];
            jobs.push_back(tmp);
        }
        sort(jobs.begin(), jobs.end());
        for (int i = 1;i < n+1;i++) jobs[i].p = max(jobs[i].p, jobs[i-1].p);
        int m = worker.size(), ans=0;
        for (int i = 0;i < m;i++){
            tmp.d=worker[i];
            ans += (upper_bound(jobs.begin(), jobs.end(), tmp)-1)->p;
        }
        return ans;
        
    }
};