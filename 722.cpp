class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        int state = 0; //ok to append
        vector<string> ret;
        string buff="";
        for (auto s:source){
            int n = s.length();
            int p = 0;
            while(p<n){
                if (state==0){
                    if (p<n-1 && s[p]=='/' && s[p+1]=='/')
                        break;
                    else if (p<n-1 && s[p]=='/' && s[p+1]=='*'){
                        state=1;
                        p+=2;
                    }
                    else buff+=s[p++];
                }
                else if (state==1){
                    if (p<n-1 && s[p]=='*' && s[p+1]=='/'){
                        state=0;
                        p+=2;
                    }
                    else p++;
                }
            }
            if (state==0 && buff.length()>0){
                ret.push_back(buff);
                buff="";
            }
        }
        return ret;
    }
};