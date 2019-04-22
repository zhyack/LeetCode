class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n1 = s1.length(), n2 = s2.length();
        vector<vector<int> > dp(n1+1, vector<int>(n2+1, 1e9));
        dp[0][0]=0;
        for (int i=1; i<=n1; i++) dp[i][0]=dp[i-1][0]+int(s1[i-1]);
        for (int i=1; i<=n2; i++) dp[0][i]=dp[0][i-1]+int(s2[i-1]);
        for (int i=1; i<=n1; i++)
            for (int j=1; j<=n2; j++){
                if (s1[i-1]==s2[j-1]) dp[i][j]=dp[i-1][j-1];
                dp[i][j] = min(dp[i][j], min(dp[i-1][j]+int(s1[i-1]),dp[i][j-1]+int(s2[j-1])));
            }
        return dp[n1][n2];
    }
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
          result.push_back(currentChar);
        }
    }
    return result;
}

int main() {
    string line;
    while (getline(cin, line)) {
        string s1 = stringToString(line);
        getline(cin, line);
        string s2 = stringToString(line);
        
        int ret = Solution().minimumDeleteSum(s1, s2);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}