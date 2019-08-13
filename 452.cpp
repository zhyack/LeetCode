struct Node{
    int l,r;
    Node(int ll, int rr){
        this->l = ll;
        this->r = rr;
    }
};
bool operator< (const Node &A, const  Node &B){
    return A.r<B.r;
}
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        vector<Node> ps;
        for (auto p:points) ps.push_back(Node(p[0],p[1]));
        sort(ps.begin(), ps.end());
        int ret = 0, p = 0;
        while(p<ps.size()){
            int x = ps[p].r;
            while(p<ps.size() && ps[p].l<=x) p++;
            ret += 1;
        }
        return ret;
    }
};