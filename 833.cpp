class Solution {
public:
    string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        map<int, int> m;
        int n = indexes.size();
        if (n==0) return S;
        for (int i = 0;i < n;i++) m[indexes[i]]=i;
        auto it = m.end();
        while(it!=m.begin()){
            it--;
            int p=it->first, i = it->second;
            int ns = sources[i].length();
            if (S.substr(p, ns) == sources[i])
               S.replace(p, ns, targets[i]); 
        }
        return S;
    }
};