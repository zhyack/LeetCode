class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        int n = s.length();
        vector<vector<int>> cnt(n+1, vector<int>(26, 0));
        for (int i = 1; i <= n;i++){
            for (int k = 0;k < 26;k++) cnt[i][k]=cnt[i-1][k];
            cnt[i][s[i-1]-'a']++;
        }
        vector<bool> ret;
        for (auto q:queries){
            int l = q[0], r = q[1], k = q[2], odd=0;
            for (int i = 0;i < 26;i++)
                if ((cnt[r+1][i]-cnt[l][i])%2==1) odd++;
            if ((r-l+1)%2==1) odd--;
            if (odd/2>k) ret.push_back(false);
            else ret.push_back(true);
        }
        return ret;
    }
};