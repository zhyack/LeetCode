class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int p = 0;
        int n = words.size();
        vector<string> ret;
        while(p<n){
            int cnt = -1, st = p;
            while(p<n && cnt+words[p].length()+1<=maxWidth){
                cnt+=words[p].length()+1;
                p++;
            }
            string t = "";
            if (p<n){
                int normal_spaces = maxWidth-cnt+p-st-1, one_more_spaces = 0;
                t += words[st];
                if (p>st+1){
                    one_more_spaces = normal_spaces%(p-st-1);
                    normal_spaces/=(p-st-1);
                    for (int i = 0;i < p-st-1;i++){
                        int spcnt = normal_spaces;
                        if (i<one_more_spaces) spcnt++;
                        for (int k = 0;k < spcnt;k++)
                            t.push_back(' ');
                        t += words[st+i+1];
                    }
                }
                else{
                    for (int k = 0;k < normal_spaces;k++)
                        t.push_back(' ');
                }
                //cout << normal_spaces << endl;
                
                
            }
            else{
                t += words[st];
                for (int i = st+1; i < p;i++) t+=" "+words[i];
                while(t.length()<maxWidth) t.push_back(' ');
            }
            ret.push_back(t);
        }
        return ret;
    }
};