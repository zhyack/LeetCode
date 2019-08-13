class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> s;
        for (string e:emails){
            string ln, dn;
            int ap = e.find('@');
            ln = e.substr(0, ap);
            dn = e.substr(ap+1, e.length()-ap-1);
            int pp = ln.find('+');
            if (pp>=0) ln = ln.substr(0,pp);
            ln.erase(remove(ln.begin(), ln.end(), '.'), ln.end());
            s.insert(ln+"@"+dn);
        }
        return s.size();
    }
};