class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0, r = s.length()-1;
        while(l<r){
            while(l<r && (s[l]<'a' || s[l]>'z') && (s[l]<'A' || s[l]>'Z') && (s[l]<'0' || s[l]>'9')) l++;
            while(l<r && (s[r]<'a' || s[r]>'z') && (s[r]<'A' || s[r]>'Z') && (s[r]<'0' || s[r]>'9')) r--;
            if (l<r){
                char a = s[l], b = s[r];
                if (s[l]>='a' && s[l]<='z') a+='A'-'a';
                if (s[r]>='a' && s[r]<='z') b+='A'-'a';
                if (a!=b) return false;
                l++;
                r--;
            }
            
        }
        return true;
    }
};