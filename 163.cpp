class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> ret;
        long long llower = lower;
        long long lupper = upper;
        llower--;
        lupper++;
        vector<long long> num(nums.begin(), nums.end());
        int n = num.size();
        if (n==0){
            if (lupper-llower==2) ret.push_back(to_string(lupper-1));
            else if (lupper-llower>2) ret.push_back(to_string(llower+1)+"->"+to_string(lupper-1));
            return ret;
        }
        if (num[0]-llower==2) ret.push_back(to_string(num[0]-1));
        else if (num[0]-llower>2) ret.push_back(to_string(llower+1)+"->"+to_string(num[0]-1));
        for (int i = 0;i < n-1;i++){
            if (num[i+1]-num[i]==2) ret.push_back(to_string(num[i+1]-1));
            else if (num[i+1]-num[i]>2) ret.push_back(to_string(num[i]+1)+"->"+to_string(num[i+1]-1));
        }
        if (lupper-num[n-1]==2) ret.push_back(to_string(lupper-1));
        else if (lupper-num[n-1]>2) ret.push_back(to_string(num[n-1]+1)+"->"+to_string(lupper-1));
        return ret;
    }
};