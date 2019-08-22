class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        const int MOD=1e9+7;
        unordered_map<long long, vector<string>> ans;
        for (auto s:strs){
            unordered_map<char, int> m;
            for (auto c:s) m[c]++;
            long long hash = 0;
            for (char c='a'; c<='z'; c++) hash = (hash*1000007%MOD+m[c]+1)%MOD;
            ans[hash].push_back(s);
        }
        vector<vector<string>> ret;
        for (auto it:ans) ret.push_back(it.second);
        return ret;
    }
};