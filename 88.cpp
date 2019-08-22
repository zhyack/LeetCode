class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p = m, x = 0, y = 0;
        vector<int> v;
        while(x<m && y<n){
            if (nums1[x]<=nums2[y])
                v.push_back(nums1[x++]);
            else v.push_back(nums2[y++]);
        }
        while(x<m) v.push_back(nums1[x++]);
        while(y<n) v.push_back(nums2[y++]);
        nums1=v;
    }
};