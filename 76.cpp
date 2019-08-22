class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> tm;
        if (t.length()==0 || s.length()==0) return "";
        for (char c:t) tm[c]++;
        int n = s.length(), m = tm.size();
        int l = 0, r = 0, retl = n+1, rets = -1;
        while(l<n){
            while(r<n && m>0){
                if (tm.find(s[r])!=tm.end()){
                    tm[s[r]]--;
                    if (tm[s[r]]==0) m--;
                }
                r++;
            }
            if (m==0 && retl>r-l) retl = r-l, rets=l;
            if (tm.find(s[l])!=tm.end()){
                if (tm[s[l]]==0) m++;
                tm[s[l]]++;
            }
            //cout << l << "," << r << endl;
            l++;
        }
        if (~rets) return s.substr(rets, retl);
        else return "";
    }
};