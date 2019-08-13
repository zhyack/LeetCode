/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */
class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int l = 0, m = (n-1)/2, r = n-1;
        while(l<r){
            int m1 = (l+m)/2, m2=(m+r+1)/2;
            int v1 = mountainArr.get(m1), v2 = mountainArr.get(m2);
            if (v1<v2) l=m1+1;
            else r=m2-1;
            m = (l+r)/2;            
        }
        l = 0, r = m;
        while(l<r){
            int m1 = (l+r)/2;
            int v = mountainArr.get(m1);
            if (v<target) l=m1+1;
            else if (v>target) r=m1-1;
            else return m1;
        }
        if (l==r && mountainArr.get(l)==target) return l;
        l = m+1, r = n-1;
        while(l<r){
            int m1 = (l+r)/2;
            int v = mountainArr.get(m1);
            if (v<target) r=m1-1;
            else if (v>target) l=m1+1;
            else return m1;
        }
        if (l==r && mountainArr.get(l)==target) return l;
        return -1;
    }
};