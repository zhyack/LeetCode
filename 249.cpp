class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<long long, vector<string>> m;
        int MOD=1e9+7;
        for (auto s:strings){
            long long hash = 0;
            if (s.length()==0) m[hash].push_back(s);
            else{
                char base=s[0];
                for (auto c:s)
                    hash = (hash*60%MOD+(int(c-base+26)%26+30))%MOD;
                m[hash].push_back(s);
            }
        }
        vector<vector<string>> ret;
        for (auto it:m)
            ret.push_back(it.second);
        return ret;
    }
};