class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        string ns = "#";
        for (int i = 0; i< n;i++){
            ns += s[i];
            ns += '#';
        }
        vector<int> dp(n*2+1, 1);
        int f=0, l=1, retf=0;
        for(int i = 0;i < n*2+1;i++){
            if (i<=f+l-1) dp[i]=min(dp[f*2-i], f+l-i);
            while(i+dp[i]<=n*2 && i-dp[i]>=0 && ns[i+dp[i]]==ns[i-dp[i]]) dp[i]+=1;
            if (i+dp[i]>f+l) l=dp[i], f=i;
            if (dp[i]>dp[retf]) retf=i;
        }
        string ret = "";
        if (ns[retf]!='#') ret += ns[retf]; 
        for (int i = 1; i < dp[retf]; i++)
            if (ns[i+retf]!='#') ret = ns[i+retf]+ret+ns[i+retf];
        return ret;
    }
};