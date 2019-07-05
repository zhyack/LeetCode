class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        vector<int> v(n+1, 0);
        stack<int> st;
        int ret = 0;
        for (int i = 0;i < n;i++){
            if (s[i]=='(') st.push(i+1);
            else if (!st.empty()){
                v[i+1]=v[st.top()-1]+i+1-st.top()+1;
                st.pop();
                ret = max(ret, v[i+1]);
            }
        }
        return ret;
    }
};