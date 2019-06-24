class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if (n<2) return n;
        int l=0, r=0, ret=0;
        vector<int> cnt(256,0);
        while(r < n){
            if (cnt[int(s[r])]){
                while(s[l]!=s[r]) cnt[int(s[l++])]--;
                cnt[int(s[l++])]--;
            }
            cnt[int(s[r++])]++;
            ret = max(ret, r-l);
        }
        return ret;
    }
};