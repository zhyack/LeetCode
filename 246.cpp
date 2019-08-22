class Solution {
public:
    bool isStrobogrammatic(string num) {
        int n = num.length();
        if (n==0) return true;
        for (int i =0; i <= n/2; i++)
            if (!(num[i]=='6' && num[n-1-i]=='9' || num[i]=='9' && num[n-1-i]=='6' || num[i]=='8' && num[n-1-i]=='8' || num[i]=='1' && num[n-1-i]=='1' || num[i]=='0' && num[n-1-i]=='0'))
                return false;
        return true;
        
    }
};