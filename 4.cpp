class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m=nums2.size();
        if (n==0 && m==0) return 0.0;
        if (n==0) return double(nums2[m/2]+nums2[(m-1)/2])/2.0;
        if (m==0) return double(nums1[n/2]+nums1[(n-1)/2])/2.0;
        int l1 = 0, r1=n-1, t=(n+m+1)/2;
        while(l1<=r1){
            int m1=(l1+r1)/2;
            int l2 = lower_bound(nums2.begin(), nums2.end(), nums1[m1])-nums2.begin();
            int r2 = upper_bound(nums2.begin(), nums2.end(), nums1[m1])-nums2.begin();
            if (m1+l2+1<=t && m1+r2+1>=t){
                if ((n+m)&1) return double(nums1[m1]);
                else return double(nums1[m1]+min(t-m1-1<m?nums2[t-m1-1]:nums1[m1+1], m1+1<n?nums1[m1+1]:nums2[t-m1-1]))/2.0;
            }
            if (m1+l2+1>t) r1=m1-1;
            else l1=m1+1;
        }
        swap(nums1, nums2);
        swap(n,m);
        l1 = 0, r1=n-1, t=(n+m+1)/2;
        while(l1<=r1){
            int m1=(l1+r1)/2;
            int l2 = lower_bound(nums2.begin(), nums2.end(), nums1[m1])-nums2.begin();
            int r2 = upper_bound(nums2.begin(), nums2.end(), nums1[m1])-nums2.begin();
            if (m1+l2+1<=t && m1+r2+1>=t){
                if ((n+m)&1) return double(nums1[m1]);
                else return double(nums1[m1]+min(t-m1-1<m?nums2[t-m1-1]:nums1[m1+1], m1+1<n?nums1[m1+1]:nums2[t-m1-1]))/2.0;
            }
            if (m1+l2+1>t) r1=m1-1;
            else l1=m1+1;
        }
        return -1;
    }
};