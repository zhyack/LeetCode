class Solution {
public:
    unordered_set<long long> buildHash(string s, int n){
        int m = s.size();
        unordered_set<long long> hash;
        hash.clear();
        if (m<n) return hash;
        vector<long long> mask(26);
        long long w = 1, MOD=1e9+7, h=0;
        mask[0]=1;
        for (int i = 1; i<26;i++) mask[i]=10001*mask[i-1]%MOD;
        for (int i = 0;i < n-1;i++)
            h = (h+mask[int(s[i]-'a')])%MOD;
        
        for (int i=n-1; i<m;i++){
            h = (h+mask[int(s[i]-'a')])%MOD;
            hash.insert(h);
            h = (h - mask[s[i-n+1]-'a']+MOD)%MOD;
        }
        return hash;
    }
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.length(), n2=s2.length();
        if (n1>n2) return false;
        unordered_set<long long> h1 = buildHash(s1, n1);
        unordered_set<long long> h2 = buildHash(s2, n1);
        for (unordered_set<long long>::iterator it=h1.begin(); it!=h1.end(); it++)
            if (h2.find(*it)!=h2.end()) return true;
        return false;
        
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

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        string s1 = stringToString(line);
        getline(cin, line);
        string s2 = stringToString(line);
        
        bool ret = Solution().checkInclusion(s1, s2);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}