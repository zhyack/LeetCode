class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int n = nums.size();
        if (n==0) return 0;
        unordered_map<int, int> count, begin, end;
        count.clear();
        int d = 0;
        for (int i=0; i<n; i++){
            if (count.find(nums[i])==count.end()) count[nums[i]]=0, begin[nums[i]]=i;
            count[nums[i]]++;
            end[nums[i]]=i;
            d = max(d, count[nums[i]]);
        }
        int ans = n;
        for (unordered_map<int, int>::iterator it = count.begin(); it!=count.end(); it++)
            if (it->second==d) ans = min(ans, end[it->first]-begin[it->first]+1);
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
        vector<int> nums = stringToIntegerVector(line);
        
        int ret = Solution().findShortestSubArray(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}