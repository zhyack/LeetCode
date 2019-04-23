class Solution {
public:
    string crackSafe(int n, int k) {
        string ret="";
        for (int i = 0;i < n-1;i++) ret+='0';
        if (n==1){
            for (int i = 0;i < k;i++) ret+=char('0'+i);
            return ret;
        }
        if (k==1) return ret+'0';
        unordered_map<int, int> h;
        h.clear();
        
        int MOD=1;
        for (int i = 0;i < n-2; i++) MOD*=10;
        int last=0;
        while(true){
            if (h.find(last)!=h.end() && h[last]==1) break;
            if (h.find(last)==h.end()) h[last]=1;
            ret+=char('0'+h[last]);
            int now = last%MOD*10+h[last];
            h[last] = (h[last]+1)%k;
            last = now;
        }
        return ret;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);
        getline(cin, line);
        int k = stringToInteger(line);
        
        string ret = Solution().crackSafe(n, k);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}