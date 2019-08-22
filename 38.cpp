class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        while(--n){
            cout << s << endl;
            int cnt = 0;
            char last=s[0];
            string t = "";
            for (auto c:s){
                if (c==last) cnt++;
                else{
                    t+=to_string(cnt);
                    t+=last;
                    cnt=1;
                    last=c;
                }
            }
            if (cnt){
                t+=to_string(cnt);
                t+=last;
            }
            s = t;
        }
        return s;
    }
};