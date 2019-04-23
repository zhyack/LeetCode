class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        unordered_map<char, char> h, rh;
        int n = words.size(), m=pattern.size();
        vector<string> ret;
        ret.clear();
        for (int i = 0;i < n; i++){
            h.clear();
            rh.clear();
            bool match=true;
            for (int j=0;j<m;j++){
                if (h.find(pattern[j]) != h.end() && h[pattern[j]]!=words[i][j] || rh.find(words[i][j]) != rh.end() && rh[words[i][j]]!=pattern[j]){
                    match=false;
                    break;
                }
                h[pattern[j]]=words[i][j];
                rh[words[i][j]]=pattern[j];
            }
            if (match) ret.push_back(words[i]);
        }
        return ret;
    }
};