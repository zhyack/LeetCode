class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> p(0);
        for (int i = 0;i < (1<<nums.size());i++){
            p.clear();
            for (int j = 0;j <= nums.size(); j++)
                if ((1<<j)&i) p.push_back(nums[j]);
            ret.push_back(p);
        }
        return ret;
    }
};