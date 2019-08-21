class Solution {
public:
    string decodeString(string s) {
        stack<string> st;
        stack<int> si;
        string str = "";
        string ret = "";
        int p = 0;
        while(p<s.length()){
            if (s[p]>='0' && s[p]<='9'){
                int num = 0;
                while(s[p]>='0' && s[p]<='9'){
                    num=num*10+s[p]-'0';
                    p++;
                }
                si.push(num);
            }
            else if (s[p]=='['){
                st.push(str);
                st.push("[");
                str = "";
                p++;
            }
            else if (s[p]==']'){
                string tmp="";
                for (int i = 0;i < si.top();i++) tmp+=str;
                si.pop();
                st.pop();
                str = st.top()+tmp;
                st.pop();
                if (st.empty()){
                    ret += str;
                    str = "";
                }
                p++;
            }
            else{
                str.append(1, s[p]);
                p++;
            }
        }
        if (str.length()>0) ret+=str;
        return ret;  
    }
};