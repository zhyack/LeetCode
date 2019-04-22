class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> last, now;
        last.clear();
        last.push_back(0);
        while(n--){
            now.clear();
            int m = last.size();
            for (int i = 0;i < m;i++) now.push_back(last[i]*2);
            for (int i = m-1;i >= 0;i--) now.push_back(last[i]*2+1);
            last = now;
        }
        return last;
        
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

string integerVectorToString(vector<int> list, int length = -1) {
    if (length == -1) {
        length = list.size();
    }

    if (length == 0) {
        return "[]";
    }

    string result;
    for(int index = 0; index < length; index++) {
        int number = list[index];
        result += to_string(number) + ", ";
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);
        
        vector<int> ret = Solution().grayCode(n);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}