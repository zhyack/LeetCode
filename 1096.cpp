void combine(unordered_set<string> &s1, unordered_set<string> &s2){
    unordered_set<string> ret;
    if (s1.size()==0) s1 = s2;
    else{
        for (auto k1:s1)
            for (auto k2:s2)
                ret.insert(k1+k2);
        s1 = ret;
    }
    
}

class Solution {
public:
    vector<string> braceExpansionII(string expression) {
        //cout << expression << endl;
        unordered_set<string> s1, s2, ret;
        int cntl = 0, cntr = 0;
        int n = expression.length();
        string s = "";
        for (int i = 0;i <= n;i++){
            if (i==n || cntl==cntr){
                if (s.length()){
                    s2.clear();
                    if (s[0]!='{'){
                        s2.insert(s);
                    }
                    else{
                        vector<string> parse = braceExpansionII(s.substr(1, s.length()-2));
                        for (auto p:parse) s2.insert(p);
                    }
                    combine(s1,s2);
                    s = "";
                }
            }
            if (i==n || cntl==cntr && expression[i]==','){
                for (auto k:s1) ret.insert(k);
                s1.clear();
            }
            if (i==n) continue;
            if (expression[i]=='{') cntl++;
            else if (expression[i]=='}') cntr++;
            if (cntl!=cntr || expression[i]!=',') s+=expression[i];
        }
        vector<string> retl;
        for (auto k:ret) retl.push_back(k);
        sort(retl.begin(), retl.end());
        return retl;
    }
};