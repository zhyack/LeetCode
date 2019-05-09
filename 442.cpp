class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> ret(0);
        for (int i = 0;i < n;i++){
            while(nums[i]>0 && nums[i]!=nums[nums[i]-1]) swap(nums[i], nums[nums[i]-1]);
            if (nums[i]>0 && nums[i]!=i+1 && nums[i]==nums[nums[i]-1]){
                ret.push_back(nums[i]);
                nums[i]=0;
            }
            
        }
        return ret;
    }
};