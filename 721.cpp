class Solution {
public:
    int top(int x, vector<int>& father){
        if (father[x]!=x) father[x] = top(father[x], father);
        return father[x];
    }
    void merge(int x, int y, vector<int>& father){
        int fx = top(x, father), fy = top(y, father);
        if (fx!=fy) father[fx]=fy;
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, vector<int>> mail2per;
        mail2per.clear();
        int n = accounts.size();
        for (int i=0; i<n; i++){
            int m = accounts[i].size();
            for (int j=1; j<m; j++)
                mail2per[accounts[i][j]].push_back(i);
        }
        vector<int> father(n);
        for (int i=0; i<n; i++) father[i]=i;
        for (unordered_map<string, vector<int>>::iterator it=mail2per.begin(); it!=mail2per.end(); it++){
            int m = it->second.size();
            for (int i=0; i<m-1; i++) merge(it->second[i], it->second[i+1], father);
        }
        vector<set<string>> accs(n);
        cout << accs.size() << endl;
        for (int i=0; i<n; i++){
            int k = top(i, father), m = accounts[i].size();
            for (int j=1; j<m; j++) accs[k].insert(accounts[i][j]);
        }
        vector<vector<string>> ret;
        ret.clear();
        for (int i=0; i<n; i++)
            if (accs[i].size()>0){
                vector<string> tmp;
                tmp.clear();
                tmp.push_back(accounts[i][0]);
                for (set<string>::iterator it=accs[i].begin(); it!=accs[i].end(); it++)
                    tmp.push_back(*it);
                ret.push_back(tmp);
            }
        return ret;
    }
};