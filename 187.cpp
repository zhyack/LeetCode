class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.length();
        vector<string> ret;
        ret.clear();
        int high=1, hash=0;
        unordered_set<int> us; 
        us.clear();
        for (int i=0; i<10 ; i++){
            hash = hash*5 + ((s[i]=='A')?1:(s[i]=='T')?2:(s[i]=='C')?3:(s[i]=='G')?4:0);
            high*=5;
        }
        high/=5;
        us.insert(hash);
        unordered_set<int> ans;
        ans.clear();
        for (int i=1; i<=n-10; i++){
            hash = hash-high*((s[i-1]=='A')?1:(s[i-1]=='T')?2:(s[i-1]=='C')?3:(s[i-1]=='G')?4:0);
            hash = hash*5+((s[i+9]=='A')?1:(s[i+9]=='T')?2:(s[i+9]=='C')?3:(s[i+9]=='G')?4:0);
            if (us.find(hash)!=us.end() && ans.find(hash)==ans.end()) ret.push_back(s.substr(i,10)), ans.insert(hash);
            else us.insert(hash);
        }
        return ret;
    }
};