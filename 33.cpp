class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n-1;
        while(l<=r){
            int m = (l+r)/2;
            if (nums[m]>target){
                if (nums[l]>nums[m]) r=m-1;
                else if (nums[l]>target) l=m+1;
                else r=m-1;
            }
            else if (nums[m]<target){
                if (nums[l]<=nums[m]) l=m+1;
                else if (nums[l]<=target) r=m-1;
                else l=m+1;
            }
            else return m;
        }
        return -1;
    }
};