class Solution {
public:
    int trailingZeroes(int n) {
        int ret = 0;
        while(n>=5){
            ret += n/5;
            n/=5;
        }
        return ret;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);
        
        int ret = Solution().trailingZeroes(n);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}