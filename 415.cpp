class Solution {
public:
    string addStrings(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        int n1 = num1.length(), n2=num2.length();
        string ret = "";
        int c = 0;
        for (int i = 0;i < max(n1,n2); i++){
            int a = 0, b = 0;
            if (i<n1) a = num1[i]-'0';
            if (i<n2) b = num2[i]-'0';
            ret.push_back(char('0'+(a+b+c)%10));
            c = (a+b+c)/10;
        }
        if (c) ret.push_back('1');
        reverse(ret.begin(), ret.end());
        return ret;
    }
};