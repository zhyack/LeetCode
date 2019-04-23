class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& A) {
        int n = unique(A.begin(), A.end())-A.begin();
        sort(A.begin(), A.end());
        vector<long long> dp(n, 1);
        unordered_map<int, int> h;
        h.clear();
        const int MOD=1e9+7;
        long long ans=0;
        for(int i=0; i<n; i++){
            for (int j=0; j<i; j++){
                if (A[i]%A[j]==0 && h.find(A[i]/A[j])!=h.end()) 
                    dp[i]=(dp[i]+dp[j]*dp[h[A[i]/A[j]]]%MOD)%MOD;
            }
            h[A[i]]=i;
            ans = (ans+dp[i])%MOD;
        }
        return ans;
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> A = stringToIntegerVector(line);
        
        int ret = Solution().numFactoredBinaryTrees(A);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}