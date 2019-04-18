class Solution {
public:
    int findSubMin(vector<int>& nums, int sl, int sr){
        int vl = nums[sl], vr = nums[sr];
        if (sr-sl<2) return min(vl, vr);
        int l = sl, r = sr;
        while(l<r){
            int m = (l+r)/2;
            if (nums[m]>vr) l=m+1;
            else if (nums[m]<vl) r=m;
            else return min(findSubMin(nums,l,m), findSubMin(nums,m+1,r));
        }
        return nums[l];
    }
    int findMin(vector<int>& nums) {
        return findSubMin(nums, 0, nums.size()-1);
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
        
        int ret = Solution().findMin(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}