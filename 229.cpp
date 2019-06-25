class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ret;
        int n = nums.size();
        if (n==0) return ret;
        nth_element(nums.begin(), nums.begin()+n/3, nums.end());
        int t1 = nums[n/3];
        nth_element(nums.begin(), nums.end()-n/3-1, nums.end());
        int t2 = nums[n-1-n/3];
        if (count(nums.begin(), nums.end(), t1)>n/3) ret.push_back(t1);
        if (t2!=t1 && count(nums.begin(), nums.end(), t2)>n/3) ret.push_back(t2);
        return ret;
    }
};