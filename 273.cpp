string ns[10]={"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
string ts[10]={"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
string mt[14] ={"Zero", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety", "Hundred", "Thousand", "Million", "Billion"};

string trans(int x){//x<10
    if (x==0) return "";
    else return ns[x];
}
string transY(int x){//x<100
    if (x<10) return trans(x%10);
    else if (x>=10 && x<20) return ts[x%10];
    else if (x%10>0) return mt[x/10]+" "+trans(x%10);
    else return mt[x/10];
}
string transH(int x){//x<1000
    if (x<100) return transY(x);
    else if (x%100>0) return ns[x/100]+" "+mt[10]+" "+transY(x%100);
    else return ns[x/100]+" "+mt[10];
}
class Solution {
public:
    string numberToWords(int num) {
        if (num==0) return ns[0];
        string ret = "";
        if (num>=1e9){
            ret += transH(num/int(1e9))+" "+mt[13];
            num %= int(1e9);
        }
        if (num>=1e6){
            if (ret.length()) ret += " ";
            ret += transH(num/int(1e6))+" "+mt[12];
            num %= int(1e6);
        }
        if (num>=1e3){
            if (ret.length()) ret += " ";
            ret += transH(num/int(1e3))+" "+mt[11];
            num %= int(1e3);
        }
        if (num>0){
            if (ret.length()) ret += " ";
            ret += transH(num);
        }
        return ret;
    }
};