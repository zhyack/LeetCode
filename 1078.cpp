class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        string to_find = first+" "+second+" ";
        int st = 0, p;
        vector<string> ret;
        while(~(p = text.find(to_find, st))){
            if (p-1!=-1 && text[p-1]!=' '){
                st = p+to_find.length();
                continue;
            }
            string tmp = text.substr(p+to_find.length());
            if (~tmp.find(' ')) tmp = tmp.substr(0, tmp.find(' '));
            if (tmp.length()>0) ret.push_back(tmp);
            st = p+to_find.length();
        }
        return ret;
    }
};