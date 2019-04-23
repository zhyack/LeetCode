class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int n = nums.size();
        int s = 0;
        for (int i = 0; i < n; i++) s+=nums[i];
        int m = s-S;
        if (m%2==1 || S>s || S<-s) return 0;
        m/=2;
        vector<int> dp(m+1, 0);
        dp[0]=1;
        for (int i = 0; i < n; i++)
            for (int j = m; j>=nums[i]; j--)
                dp[j] += dp[j-nums[i]];
        return dp[m];
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

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        getline(cin, line);
        int S = stringToInteger(line);
        
        int ret = Solution().findTargetSumWays(nums, S);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}