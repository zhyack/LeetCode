int deal(string s){
    char m = 'z'+1;
    int cnt = 0;
    for (auto c:s){
        if (c<m){
            m = c;
            cnt = 0;
        }
        if (c==m) cnt++;
    }
    return cnt;
}

class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> vq, vw;
        for (auto q:queries) vq.push_back(deal(q));
        for (auto w:words) vw.push_back(deal(w));
        vector<int> ret;
        for (int x:vq){
            int cnt = 0;
            for (int y:vw) if (x<y) cnt++;
            ret.push_back(cnt);
        }
        return ret;
    }
};