/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/
class Solution {
public:
    vector<Interval*> employeeFreeTime(vector<vector<Interval*>>& schedule) {
        const int INF=1e8+1;
        vector<Interval*> ret;
        map<int, int> m;
        m[-INF]=INF;
        int n = schedule.size();
        for (int i = 0;i < n;i++){
            auto st = m.begin();
            for (int j = 0;j < schedule[i].size();j++){
                int l = schedule[i][j]->start, r=schedule[i][j]->end-1;
                // cout << "to erase [" << l << "," << r << "]" << endl; 
                if (l>r) continue;
                while(l>st->second) st++;
                if (l<st->first) l = st->first;
                // cout << "begin [" << st->first << "," << st->second << "]" << endl;
                auto en = st;
                while(r>en->second) en++;
                if (r<en->first){
                    en--;
                    r=en->second;
                }
                // cout << "end [" << en->first << "," << en->second << "]" << endl;
                if (l>r) continue;
                // cout << "final erase [" << l << "," << r << "]" << endl; 
                int tmp = en->second;
                st->second=l-1;
                vector<int> to_erase;
                for (auto k=en; k!=st; k--)
                    to_erase.push_back(k->first);
                for (auto k:to_erase) m.erase(k);
                m[r+1]=tmp;
                if (r+1>m[r+1]) m.erase(r+1);
                if (st->first>st->second){
                    tmp = st->first;
                    st++;
                    m.erase(tmp);
                }
                // for (auto it:m) cout << "[" << it.first << "," << it.second << "]  ";
                // cout << endl;
            }
        }
        for (auto it:m)
            if (it.first!=-INF && it.second !=INF)
                ret.push_back(new Interval(it.first, it.second+1));
        return ret;
    }
};