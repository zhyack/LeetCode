int calc(string s, bool allow_zero){
    int n = s.length();
    if (n==0) return 1;
    if (n==1){
        if (s[0]>='8') return 3;
        else if (s[0]>='1') return 2;
        else return 1;
    }
    int low_ret = 0;
    if (!allow_zero){
        string tmp = "";
        tmp.append(n-1, '9');
        low_ret += calc(tmp, false);
    }
    int cnt = 0;
    if (s[0]>'8'){
        cnt = 3;
        if (allow_zero) cnt++;
        for (int i = 1;i < n/2;i++) cnt*=5;
        if (n%2==1) cnt*=3;
        if (s[0]!='9'){cnt = cnt;}
        else if (s[n-1]>='6') cnt+=calc(s.substr(1, n-2), true);
        else{
            int c = 1;
            string tmp = "";
            for (int i = n-2; i>0; i--){
                if (c==1){
                    if (s[i]=='0') tmp+='9';
                    else tmp+=s[i]-1, c=0;
                } 
                else tmp+=s[i];
            }
            reverse(tmp.begin(), tmp.end());
            if (c!=1) cnt+=calc(tmp, true);
        }
    }
    else if (s[0]>'6'){
        cnt = 2;
        if (allow_zero) cnt++;
        for (int i = 1;i < n/2;i++) cnt*=5;
        if (n%2==1) cnt*=3;
        if (s[0]!='8'){cnt = cnt;}
        else if (s[n-1]>='8') cnt+=calc(s.substr(1, n-2), true);
        else{
            int c = 1;
            string tmp = "";
            for (int i = n-2; i>0; i--){
                if (c==1){
                    if (s[i]=='0') tmp+='9';
                    else tmp+=s[i]-1, c=0;
                } 
                else tmp+=s[i];
            }
            reverse(tmp.begin(), tmp.end());
            if (c!=1) cnt+=calc(tmp, true);
        }
    }
    else if (s[0]>'1'){
        cnt = 1;
        if (allow_zero) cnt++;
        for (int i = 1;i < n/2;i++) cnt*=5;
        if (n%2==1) cnt*=3;
        if (s[0]!='6'){cnt = cnt;}
        else if (s[n-1]>='9') cnt+=calc(s.substr(1, n-2), true);
        else{
            int c = 1;
            string tmp = "";
            for (int i = n-2; i>0; i--){
                if (c==1){
                    if (s[i]=='0') tmp+='9';
                    else tmp+=s[i]-1, c=0;
                } 
                else tmp+=s[i];
            }
            reverse(tmp.begin(), tmp.end());
            if (c!=1) cnt+=calc(tmp, true);
        }
    }
    else if (s[0]>'0'){
        cnt = 0;
        if (allow_zero) cnt++;
        for (int i = 1;i < n/2;i++) cnt*=5;
        if (n%2==1) cnt*=3;
        if (s[0]!='1'){cnt = cnt;}
        else if (s[n-1]>='1') cnt+=calc(s.substr(1, n-2), true);
        else{
            int c = 1;
            string tmp = "";
            for (int i = n-2; i>0; i--){
                if (c==1){
                    if (s[i]=='0') tmp+='9';
                    else tmp+=s[i]-1, c=0;
                } 
                else tmp+=s[i];
            }
            reverse(tmp.begin(), tmp.end());
            if (c!=1) cnt+=calc(tmp, true);
        }
    }
    else if (s[0]=='0' && allow_zero){
        if (n==2){cnt = 1;}
        else cnt = calc(s.substr(1, n-2), true);
    }
    // cout << s << " : " <<  cnt <<  "," << low_ret << endl;
    return cnt+low_ret;
}

int isStro(string s){
    int n = s.length();
    for (int i = 0;i < n/2;i++){
        if (s[i]=='6'&&s[n-i-1]=='9' || s[i]=='9'&&s[n-i-1]=='6' || s[i]=='8' && s[n-i-1]=='8' || s[i]=='0'&&s[n-i-1]=='0' || s[i]=='1'&&s[n-i-1]=='1') continue;
        return 0;
    }
    if (n%2==1 && (s[n/2]!='0' && s[n/2]!='1' && s[n/2]!='8')) return 0;
    return 1;
}
class Solution {
public:
    int strobogrammaticInRange(string low, string high) {
        return max(calc(high, false)-calc(low, false)+isStro(low),0);
    }
};