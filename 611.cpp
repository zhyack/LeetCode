class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int ret = 0;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0;i < n;i++){
            if (nums[i]==0) continue;
            int p = i+1;
            for (int j = i+1;j < n;j++){
                while(p<n && nums[p]<nums[i]+nums[j]) p++;
                ret += p-j-1;
                //cout << i << " " << j << ":" << ret << endl;
            }
        }
        return ret;
    }
};