void dfs(int d, string s, string &o, vector<bool> &visited, vector<string> &ret){
    if (d==5){
        if (int(s[0]-'0')*10+s[1]-'0'<24 && int(s[3]-'0')*10+s[4]-'0'<60) ret.push_back(s);
        return;
    }
    if (d==2) dfs(d+1, s+":", o, visited, ret);
    else for (int i = 0;i < 5;i++){
        if (visited[i]) continue;
        dfs(d+1, s+o.substr(i,1), o, visited, ret);
    }
}

class Solution {
public:
    string nextClosestTime(string time) {
        vector<string> validTimes;
        vector<bool> visited(5,false);
        visited[2]=true;
        dfs(0, "", time, visited, validTimes);
        sort(validTimes.begin(), validTimes.end());
        bool find = false;
        for (auto s:validTimes){
            if (s==time) find=true;
            if (find && s!=time) return s;
        }
        return validTimes[0];
    }
};