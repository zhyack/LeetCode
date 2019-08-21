class Solution {
public:
    string alienOrder(vector<string>& words) {
        string ret="";
        unordered_map<char, unordered_set<char>> m;
        unordered_map<char, int> d;
        int n = words.size();
        if (n==1) return words[0];
        for (int i = 0;i < n-1;i++){
            bool get_relation=false;
            for (int k = 0;k < max(words[i].length(), words[i+1].length()); k++){
                char a = '0', b = '0';
                if (k<words[i].length()) a = words[i][k];
                if (k<words[i+1].length()) b = words[i+1][k];
                if (m.find(a)==m.end()) m[a]=unordered_set<char>(), d[a]=0;
                if (m.find(b)==m.end()) m[b]=unordered_set<char>(), d[b]=0;
                if (get_relation || a==b) continue;
                else{
                    if (m[a].find(b)==m[a].end()){
                        m[a].insert(b);
                        d[b]++;
                        //cout << a << "<" << b << endl;
                    }
                    get_relation=true;
                }
            }
        }
        if (d['0']>0) return "";
        queue<char> q;
        for (auto it:d)
            if (it.second==0)
                q.push(it.first);
        while(!q.empty()){
            char c = q.front();
            q.pop();
            if (c!='0') ret.push_back(c);
            for (char suff:m[c]){
                d[suff]--;
                if (d[suff]==0) q.push(suff);
            }
        }
        for (auto it:d)
            if (it.second!=0) return "";
        return ret;
    }
};