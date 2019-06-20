struct Node{
    int x,y,id;
    bool l;
};
bool operator <(const Node &A, const Node &B){
    return A.x < B.x || A.x==B.x && (A.l && !B.l || A.l && B.l && A.y>B.y || !A.l && !B.l && A.y<B.y);
}

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> ret;
        int n = buildings.size();
        vector<Node> lines;
        for (int i = 0;i < n;i++){
            Node tmp;
            tmp.y = buildings[i][2];
            tmp.id = i;
            tmp.x = buildings[i][0];
            tmp.l = true;
            lines.push_back(tmp);
            tmp.x = buildings[i][1];
            tmp.l = false;
            lines.push_back(tmp);
        }
        sort(lines.begin(), lines.end());
        priority_queue<Node> q;
        vector<bool> inq(n, false);
        for (int i = 0;i < n*2; i++){
            if (lines[i].l){
                if (q.empty() || lines[i].y>q.top().x){
                    vector<int> tmp({lines[i].x, lines[i].y});
                    ret.push_back(tmp);
                }
                swap(lines[i].x, lines[i].y);
                q.push(lines[i]);
                inq[lines[i].id]=true;
            }
            else{
                inq[lines[i].id]=false;
                while(!q.empty() && !inq[q.top().id]) q.pop();
                if (q.empty()){
                    vector<int> tmp({lines[i].x, 0});
                    ret.push_back(tmp);
                }
                else if (lines[i].y>q.top().x){
                    vector<int> tmp({lines[i].x, q.top().x});
                    ret.push_back(tmp);
                }
            }
        }
        return ret;
    }
};