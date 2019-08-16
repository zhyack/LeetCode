class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> m;
        for (char c:p) m[c]++;
        int left=m.size(), l=0, r=0, n=s.length();
        vector<int> ret;
        if (left==0){
            for (int i = 0;i < n;i++) ret.push_back(i);
            return ret;
        }
        while(r<n){
            while(r<n && left>0){
                m[s[r]]--;
                if (m[s[r]]==0) left--;
                else if (m[s[r]]<0){
                    left++;
                    r++;
                    break;
                }
                r++;
            }
            if (left==0){
                ret.push_back(l);
                m[s[l]]++;
                left++;
                l++;
            }
            else{
                while(l<r){
                    m[s[l]]++;
                    if (m[s[l]]==0){
                        left--;
                        l++;
                        break;
                    }
                    else if (m[s[l]]==1)
                        left++;
                    l++;
                }
            }
        }
        return ret;
    }
};