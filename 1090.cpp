struct Node{
    int v, l;
    Node(int v, int l){
        this->v=v;
        this->l=l;
    }
};
bool operator <(const Node& A, const Node& B){
    return A.v<B.v;
}
class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int num_wanted, int use_limit) {
        priority_queue<Node> q;
        int n = values.size();
        if (n==0) return 0;
        for (int i = 0;i < n;i++) q.push(Node(values[i], labels[i]));
        unordered_map<int, int> mcnt;
        int ret = 0, rcnt = 0;
        while(!q.empty()){
            Node item = q.top();
            q.pop();
            if (rcnt==num_wanted) continue;
            if (mcnt[item.l]==use_limit) continue;
            ret += item.v;
            mcnt[item.l]++;
            rcnt ++;
        }
        return ret;
    }
};