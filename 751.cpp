long long ip2int(string ip){
    long long ret;
    long long a[4]={0,0,0,0};
    int p = 0;
    for (char c:ip){
        if (c=='.'){
            p++;
            continue;
        }
        a[p] = a[p]*10+int(c-'0');
    }
    return a[0]*(1<<24)+a[1]*(1<<16)+a[2]*(1<<8)+a[3];
}

string int2str(int i){
    if (i==0) return "0";
    string ret = "";
    while(i){
        ret.append(1,char(i%10+'0'));
        i/=10;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

string int2ip(long long ip){
    int a[4]={0,0,0,0};
    a[0] = ip/(1<<24);
    a[1] = ip%(1<<24)/(1<<16);
    a[2] = ip%(1<<16)/(1<<8);
    a[3] = ip%(1<<8);
    return int2str(a[0])+"."+int2str(a[1])+"."+int2str(a[2])+"."+int2str(a[3]);
}

class Solution {
public:
    vector<string> ipToCIDR(string ip, int n) {
        vector<string> ret;
        long long st = ip2int(ip);
        unordered_map<long long, string> m;
        for (int i = 0;i < 32;i++)
            m[1<<i]=int2str(32-i);
        while(n){
            long long lowbit = st&-st;
            while(lowbit>n) lowbit/=2;
            ret.push_back(int2ip(st)+"/"+m[lowbit]);
            st+=lowbit;
            n-=lowbit;
        }
        return ret;
    }
};