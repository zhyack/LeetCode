class Solution {
public:
    int expressiveWords(string S, vector<string>& words) {
        int ret = 0;
        for (auto w:words){
            if (w.length()>S.length()) continue;
            int x=0, y=0, n1 = S.length(), n2=w.length();
            bool match = true;
            while(x<n1 && y<n2){
                if (S[x]!=w[y]){
                    match=false;
                    break;
                }
                char c = S[x];
                int cntx = 0, cnty = 0;
                while(x<n1 && S[x]==c) x++, cntx++;
                while(y<n2 && w[y]==c) y++, cnty++;
                if (cntx<cnty || cntx>cnty && cntx<3){
                    match=false;
                    break;
                }
                
            }
            if (x==n1 && y==n2 && match) ret++;
        }
        return ret;
    }
};