class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        unordered_set<int> s;
        vector<vector<int>> ret(0);
        unordered_map<int, unordered_set<int>> rs;
        for (int j = 1;j < n-1; j++){
            if (s.find(nums[j-1])==s.end()) s.insert(nums[j-1]);
            for (int k = j+1; k < n; k++){
                if (s.find(-(nums[j]+nums[k]))!=s.end()){
                    if (rs.find(nums[j])!=rs.end())
                        if (rs[nums[j]].find(nums[k])!=rs[nums[j]].end())
                            continue;
                        else rs[nums[j]].insert(nums[k]);
                    else{
                        rs[nums[j]]=unordered_set<int>();
                        rs[nums[j]].insert(nums[k]);
                    }
                    ret.push_back(vector<int>({-(nums[j]+nums[k]), nums[j], nums[k]}));
                }
            }
        }
        return ret;
    }
};