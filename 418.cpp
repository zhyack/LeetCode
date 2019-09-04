class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        vector<int> slen;
        for (auto s:sentence){
            if (s.length()>cols) return 0;
            slen.push_back(s.length());
        }
        if (slen.size()==0) return 0;
        int r = 0, p = 0, w = 0, ret = 0;
        unordered_map<int, pair<int, int>> m;
        while(r<rows){
            if (slen[w]>cols-p){
                r++,p=0;
                if (m.find(w)!=m.end()){
                    int loop=r-m[w].first, lv = ret-m[w].second;
                    ret += (rows-r)/loop*lv;
                    r+=(rows-r)/loop*loop;
                    m.clear();
                }
                m[w]=make_pair(r, ret);
            }
            if (r==rows) break;
            p+=slen[w++]+1;
            if (w==slen.size()) ret++,w=0;
        }
        return ret;
    }
};