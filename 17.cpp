const vector<string> m({"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"});

void dfs(int d, string &digits, string r, vector<string> &ret){
    if (d==digits.length()){
        if (r.length()) ret.push_back(r);
        return;
    }
    int k = int(digits[d]-'0');
    for (int i = 0;i < m[k].length(); i++) dfs(d+1, digits, r+m[k][i], ret);
}

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ret;
        string route="";
        dfs(0, digits, route, ret);
        return ret;
    }
};