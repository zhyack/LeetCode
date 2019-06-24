class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.length(), loopn=(numRows-1)*2;
        if (n==0 || loopn==0) return s;
        vector<bool> visited(n+loopn, false);
        queue<int> q;
        for (int k = 0;k <= (n-1+loopn)/loopn; k++) q.push(k*loopn), visited[k*loopn]=true;
        string ret = "";
        while(!q.empty()){
            int t = q.front();
            q.pop();
            if (t>=0 && t<n) ret += s[t];
            if (t-1>=0 && !visited[t-1]) q.push(t-1), visited[t-1]=true;
            if (t+1<n && !visited[t+1]) q.push(t+1), visited[t+1]=true;
        }
        return ret;
    }
};