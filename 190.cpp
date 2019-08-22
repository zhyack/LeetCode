class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ret=0;
        int cnt = 0;
        while(n){
            ret = ret*2+n%2;
            n/=2;
            cnt++;
        }
        while(cnt<32) ret*=2, cnt++;
        return ret;
    }
};