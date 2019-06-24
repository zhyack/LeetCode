class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ret = "";
        int n = strs.size();
        if (n==0) return ret;
        int m = strs[0].length();
        for (int k = 0;k < m; k++){
            bool b = true;
            for (int i = 1;i < n; i++)
                if (k>strs[i].length() || strs[i][k]!=strs[0][k]){
                    b = false;
                    break;
                }
            if (b) ret+=strs[0][k];
            else break;
        }
        return ret;
        
    }
};