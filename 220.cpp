class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (t<0) return false;
        int n = nums.size();
        map<long long, int> m;
        for (int i=0; i<n ;i++){
            if (i>k){
                m[nums[i-k-1]]--;
                if (m[nums[i-k-1]]==0) m.erase(nums[i-k-1]);
            }
            long long tmp = nums[i];
            map<long long, int>::iterator it1 = m.lower_bound(tmp-t), it2 = m.upper_bound(tmp+t);
            if (it1!=it2) return true;
            if (m.find(nums[i])==m.end()) m[nums[i]]=0;
            m[nums[i]]++;
        }
        return false;
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

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        getline(cin, line);
        int k = stringToInteger(line);
        getline(cin, line);
        int t = stringToInteger(line);
        
        bool ret = Solution().containsNearbyAlmostDuplicate(nums, k, t);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}