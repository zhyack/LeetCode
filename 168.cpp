class Solution {
public:
    string convertToTitle(int n) {
        string ret = "";
        n--;
        long long total = 26, bit = 1;
        while(n>=total){
            n-=total;
            total*=26;
            bit++;
        }
        while(n){
            ret+=char(n%26+'A');
            n/=26;
        }
        while(ret.length()<bit) ret+="A";
        reverse(ret.begin(), ret.end());
        return ret;
    }
};