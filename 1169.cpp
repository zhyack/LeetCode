struct Node{
    int name, time, amount, city;
    string trans;
    Node(int n, int t, int a, int c, string s){
        name = n;
        time = t;
        amount = a;
        city = c;
        trans = s;
    }
};
bool operator<(const Node &A, const Node&B){
    return A.name<B.name || (A.name==B.name && A.time<B.time);
}
class Solution {
public:
    vector<string> invalidTransactions(vector<string>& transactions) {
        vector<Node> v;
        unordered_map<string, int> ns, cs;
        int nscnt=0, cscnt=0;
        for (auto s:transactions){
            int st = 0;
            string name = s.substr(st, s.find(',', st));
            st += name.length()+1;
            string time = s.substr(st, s.find(',', st)-st);
            st += time.length()+1;
            string amount = s.substr(st, s.find(',', st)-st);
            st += amount.length()+1;
            string city = s.substr(st);
            if (ns.find(name)==ns.end())
                ns[name]=nscnt++;
            if (cs.find(city)==cs.end())
                cs[city]=cscnt++;
            v.push_back(Node(ns[name], stoi(time), stoi(amount), cs[city], s));
        }
        sort(v.begin(), v.end());
        vector<string> ret;
        for (int i = 0;i < v.size();i++){
            if (v[i].amount>1000){
                ret.push_back(v[i].trans);
                continue;
            }
            for (int j = 0;j < v.size(); j++){
                if (v[i].name==v[j].name && abs(v[i].time-v[j].time)<=60 && v[i].city!=v[j].city){
                    ret.push_back(v[i].trans);
                    break;
                }
            }
        }
        return ret;
    }
};