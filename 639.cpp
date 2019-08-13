const int MOD=1e9+7;
class Solution {
public:
    int numDecodings(string s) {
        unordered_map<string, int> m;
        m["1"]=m["2"]=m["3"]=m["4"]=m["5"]=m["6"]=m["7"]=m["8"]=m["9"]=1;
        m["0"]=0;
        m["*"]=9;
        m["0*"]=0;
        m["1*"]=9;
        m["2*"]=6;
        m["3*"]=m["4*"]=m["5*"]=m["6*"]=m["7*"]=m["8*"]=m["9*"]=0;
        m["*0"]=m["*1"]=m["*2"]=m["*3"]=m["*4"]=m["*5"]=m["*6"]=2;
        m["*7"]=m["*8"]=m["*9"]=1;
        m["**"]=15;
        unordered_map<int, string> t;
        t[0]="0", t[1]="1", t[2]="2", t[3]="3", t[4]="4", t[5]="5", t[6]="6", t[7]="7", t[8]="8", t[9]="9";
        for (int i = 0;i < 10;i++) m[t[0]+t[i]]=0;
        for (int i = 1;i < 10;i++)
            for (int j = 0;j < 10;j++)
                if (i*10+j<27) m[t[i]+t[j]]=1;
                else m[t[i]+t[j]]=0;

        int n = s.length();
        vector<long long> dp(n);
        dp[0]=m[s.substr(0,1)];
        if (n>1) dp[1]=m[s.substr(0,2)]+dp[0]*m[s.substr(1,1)];
        for (int i = 2;i < n;i++) dp[i]=dp[i-2]*m[s.substr(i-1,2)]%MOD+dp[i-1]*m[s.substr(i,1)]%MOD;
        return dp[n-1]%MOD;
    }
};