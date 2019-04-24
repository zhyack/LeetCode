class Solution {
public:
    void dfs(string s, unordered_map<string, vector<pair<string, double>>>& connections, unordered_map<string, double>& h, unordered_map<string, string>& root){
        if (root.find(s)==root.end()) root[s]=s;
        if (h.find(s)==h.end()) h[s]=1.0;
        for (const auto& it:connections[s]){
            if (h.find(it.first)==h.end()){
                h[it.first]=h[s]/it.second;
                root[it.first]=root[s];
                dfs(it.first, connections, h, root);
            }
        }
    }
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        unordered_map<string, double> h;
        h.clear();
        unordered_map<string, string> root;
        root.clear();
        int n = values.size();
        unordered_map<string, vector<pair<string, double>>> connections;
        connections.clear();
        for (int i = 0;i < n;i++){
            if (values[i]==0.0){
                h[equations[i].first]=0.0;
                continue;
            }
            if (connections.find(equations[i].first)==connections.end()) connections[equations[i].first]=vector<pair<string, double>>(0);
            connections[equations[i].first].push_back(make_pair(equations[i].second, values[i]));
            if (connections.find(equations[i].second)==connections.end()) connections[equations[i].second]=vector<pair<string, double>>(0);
            connections[equations[i].second].push_back(make_pair(equations[i].first, 1.0/values[i]));
        }
        for (const auto &it:connections)
            if (h.find(it.first)==h.end()) dfs(it.first, connections, h, root);
        int m = queries.size();
        vector<double> ret;
        for (int i=0;i < m;i++){
            if (h.find(queries[i].first)==h.end() || h.find(queries[i].second)==h.end() || root[queries[i].first]!=root[queries[i].second] && h[queries[i].first]!=0.0) ret.push_back(-1.0);
            else ret.push_back(h[queries[i].first]/h[queries[i].second]);
        }
        return ret;
    }
};