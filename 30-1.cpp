const int MOD=1e9+7;
long long getHash(string s, int m){
    long long h=0;
    for (int i = 0;i < m; i++) h = (h*30%MOD+int(s[i]-'a')+1)%MOD;
    return h;
}
vector<long long> buildHashList(string s, int m){
    int n = s.length();
    vector<long long> ret(n, 0);
    if (n < m) return ret;
    ret[0] = getHash(s, m);
    long long p = 1;
    for (int i = 0;i < m; i++) p = p*30%MOD;
    for (int i = m;i < n; i++)
        ret[i-m+1] = ((ret[i-m]*30%MOD-p*(int(s[i-m]-'a')+1)%MOD+MOD)%MOD+int(s[i]-'a')+1)%MOD;
    return ret;
}
unordered_map<long long, int> buildHashSet(vector<string>& words, int m){
    int n = words.size();
    unordered_map<long long, int> ret;
    for (int i = 0;i < n; i++){
        long long h = getHash(words[i], m);
        if (ret.find(h)==ret.end()) ret[h]=0;
        ret[h]++;
    }
    return ret;
}

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = s.length(), k = words.size();
        vector<int> ret;
        if (k==0) return ret;
        int m = words[0].length();
        if (n==0 || n<k*m) return ret;
        vector<long long> h = buildHashList(s, m);
        unordered_map<long long, int> ms = buildHashSet(words, m); 
        for (int i = 0;i<= n-k*m; i++){
            unordered_map<long long, int> tmp = ms;
            bool find = true;
            for (int j = 0;j < k;j++){
                if (tmp.find(h[i+j*m])==tmp.end()){
                    find = false;
                    break;
                }
                if (--tmp[h[i+j*m]] == 0) tmp.erase(h[i+j*m]);
            }
            if (find) ret.push_back(i);
        }
        return ret;
    }
};