// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long l = 1, r= n;
        while(l<r){
            long long m = (l+r)/2;
            if (isBadVersion(int(m))) r=m;
            else l=m+1;
        }
        return l;
    }
};