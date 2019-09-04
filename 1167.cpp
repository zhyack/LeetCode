class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        priority_queue<int, vector<int>, greater<int>> q;
        for (auto s:sticks) q.push(s);
        if (q.empty()) return 0;
        int ret = 0;
        while(q.size()>1){
            int x = q.top();
            q.pop();
            int y = q.top();
            q.pop();
            ret += x+y;
            q.push(x+y);
        }
        return ret;
    }
};