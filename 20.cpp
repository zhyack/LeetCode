class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int n = s.length();
        for (int i = 0;i < n;i++){
            if (s[i]=='{' || s[i]=='[' || s[i]=='(') st.push(s[i]);
            else if (s[i]==')' && (st.size()==0 || st.top()!='(')) return false;
            else if (s[i]==']' && (st.size()==0 || st.top()!='[')) return false;
            else if (s[i]=='}' && (st.size()==0 || st.top()!='{')) return false;
            else st.pop();
        }
        if (st.size()) return false;
        return true;
    }
};