class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        set<int> s;
        int ret = nums[0]+nums[1]+nums[2];
        for (int i = 1;i < n-1; i++)
            for (int j = 0;j < i;j++){
                s.insert(nums[i]+nums[j]);
                int k=i+1;
                set<int>::iterator it = s.lower_bound(target-nums[k]);
                if (it != s.end()){
                    if (abs(*it+nums[k]-target)<abs(ret-target)) ret = *it+nums[k];
                }
                if (it != s.begin()){
                    it--;
                    if (abs(*it+nums[k]-target)<abs(ret-target)) ret = *it+nums[k];
                }
            }
        return ret;
    }
};