class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        if (n==0) return 0;
        sort(citations.begin(), citations.end());
        vector<int> ids, sums;
        ids.clear();
        ids.push_back(-1e9);
        ids.push_back(citations[0]);
        sums.clear();
        sums.push_back(0);
        sums.push_back(1);
        int m = 1;
        for (int i=1;i < n;i++){
            if (citations[i]!=citations[i-1]) 
                ids.push_back(citations[i]), sums.push_back(sums[m++]);
            sums[m]++;
        }
        int p = m;
        for (int h=n;h>=0;h--){
            while(ids[p]>h) p--;
            int gt = n-sums[p], lt = sums[p];
            if (ids[p]==h) gt+=sums[p]-sums[p-1];
            if (gt>=h && lt>=n-h) return h;
        }
        return 0;
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
        vector<int> citations = stringToIntegerVector(line);
        
        int ret = Solution().hIndex(citations);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}